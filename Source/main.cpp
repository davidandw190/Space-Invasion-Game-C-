
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <chrono>
#include <random>
#include "Headers/Global.hpp"
#include "Headers/Player.hpp"
#include "Headers/EnemyManager.hpp"

int main() {
    std::chrono::microseconds lag(0);   // to keep track of time between frames
    std::chrono::steady_clock::time_point prev_time;    // used to comp elapsed time between frames

    // random number generator using the current time as seed value
    std::mt19937_64 random_engine(
            std::chrono::system_clock::now().time_since_epoch().count()
    );

    //  to handle user input
    sf::Event event;

    sf::RenderWindow window(sf::VideoMode(SCREEN_RESIZE * SCREEN_WIDTH, SCREEN_RESIZE * SCREEN_HEIGHT),
                            "TEST Retro Shooter Game - VERSION 0.2",
                            sf::Style::Close);
    window.setView(sf::View(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT)));


    sf::Sprite background_sprite;
    sf::Texture background_texture;

    background_texture.loadFromFile(R"(C:\Users\40787\Desktop\PP-SPACE-INVASION\Source\Resources\Background.png)");
    background_sprite.setTexture(background_texture);

    Player player;

    EnemyManager enemyManager;

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

            if (1 == enemyManager.reached_player(player.get_y())) {
                player.die();
            }

            player.update(random_engine);
            enemyManager.update(random_engine);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                player.reset();
            }
        }

        window.clear();
        window.draw(background_sprite);

        if (!player.get_dead()) {
            player.draw(window);
            enemyManager.draw(window);
        }

        window.display();
    }

    return 0;
}