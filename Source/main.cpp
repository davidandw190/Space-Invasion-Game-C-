#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <chrono>
#include <random>
#include "Headers/Global.hpp"
#include "Headers/Player.hpp"
#include "Headers/EnemyManager.hpp"
#include "Headers/BonusEnemy.hpp"

int main() {
    std::chrono::microseconds lag(0);   // to keep track of time between frames
    std::chrono::steady_clock::time_point prev_time;    // used to comp elapsed time between frames

    // random number generator using the current time as seed value
    std::mt19937_64 random_engine(
            std::chrono::system_clock::now().time_since_epoch().count()
    );

    bool game_over = false;
    bool next_wave = false;

    unsigned short curr_wave = 0;
    unsigned short next_wave_timer = NEXT_LEVEL_TRANSITION;

    //  to handle user input
    sf::Event event;

    sf::RenderWindow window(sf::VideoMode(SCREEN_RESIZE * SCREEN_WIDTH, SCREEN_RESIZE * SCREEN_HEIGHT),
                            "TEST Retro Shooter Game - VERSION 0.5",
                            sf::Style::Close);
    window.setView(sf::View(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT)));


    sf::Sprite background_sprite;
    sf::Texture background_texture;

    background_texture.loadFromFile(R"(C:\Users\40787\Desktop\PP-SPACE-INVASION\Source\Resources\Background.png)");
    background_sprite.setTexture(background_texture);

    Player player;

    EnemyManager enemyManager;

    BonusEnemy bonus_enemy(random_engine);

    prev_time = std::chrono::steady_clock::now();   // the initial value of prev_time

    while (window.isOpen()) {

        // to store the computed elapsed time since the last frame
        std::chrono::microseconds delta_time =
                std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - prev_time);

        lag += delta_time;
        prev_time += delta_time;

        while (FRAME_DURATION <= lag) {
            lag -= FRAME_DURATION;

            while (window.pollEvent(event)) {
                switch (event.type) {
                    case sf::Event::Closed:
                        window.close();
                        break;
                }
            }

            if (player.get_dead_animation_over()) {
                game_over = true;
            }

            if (enemyManager.reached_player(player.get_y())) {
                player.die();
            }

            if (!game_over) {
                if (enemyManager.get_enemies().empty()) {
                    if (0 == next_wave_timer)
                    {
                        next_wave = false;

                        curr_wave++;
                        next_wave_timer = NEXT_LEVEL_TRANSITION;

                        player.reset();

                        enemyManager.reset(curr_wave);

                        bonus_enemy.reset(true, random_engine);
                    } else {
                        next_wave = true;

                        next_wave_timer--;
                    }
                } else {
                    player.update(random_engine, enemyManager.get_enemy_bullets(), enemyManager.get_enemies(), bonus_enemy);
                    enemyManager.update(random_engine);
                    bonus_enemy.update(random_engine);
                }


            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {

                game_over = false;
                curr_wave = 0;
                player.reset();
                enemyManager.reset(0);
                bonus_enemy.reset(true, random_engine);
            }
        }

        window.clear();
        window.draw(background_sprite);

        if (!player.get_dead()) {
            player.draw(window);
            enemyManager.draw(window);
            bonus_enemy.draw(window);
        }

        window.display();
    }

    return 0;
}