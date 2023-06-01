#include <iostream>
#include <SFML/Graphics.hpp> // for display
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <chrono>             // for timing
#include <random>
#include "Headers/Global.hpp"
#include "Headers/Player.hpp"


int main() {

    std::chrono::microseconds lag(0);    // will use it to make the decuple the framerate and make it independent,
    std::chrono::steady_clock::time_point prev_time;    // will use it to compute the elapsed time

    std::mt19937_64 random_engine(
            std::chrono::system_clock::now().time_since_epoch().count()
    );

    sf::RenderWindow window(sf::VideoMode(SCREEN_RESIZE * SCREEN_WIDTH, SCREEN_RESIZE * SCREEN_HEIGHT),
                            "TEST Retro Shooter Game - VERSION 0.2",
                            sf::Style::Close);

    window.setView(sf::View(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT)));

    sf::Sprite background_sprite;
    sf::Texture background_texture;

    background_texture.loadFromFile(R"(C:\Users\40787\Desktop\PP-SPACE-INVASION\Source\Resources\Background.png)");
    background_sprite.setTexture(background_texture);

    prev_time = std::chrono::steady_clock::now();

    Player player;

    while (window.isOpen()) {

        sf::Event event{};

        std::chrono::microseconds delta_time =
                std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - prev_time);

        lag += delta_time; // the lag is now a separate entity, and we will generate the frames in the game according
                            // to its current value

        prev_time += delta_time;

        while (FRAME_DURATION <= lag) {
            lag -= FRAME_DURATION;


            while (window.pollEvent(event)) {
                switch (event.type) {
                    case sf::Event::Closed: {
                        window.close();
                    }
                    case sf::Event::Resized: {  // most likely we will not make the window resizable
                        break;
                    }
                }

            }

            if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                player.reset();
            }

        }

        if (FRAME_DURATION > lag) {
            window.clear();
            window.draw(background_sprite);
        }

        window.draw(background_sprite);
        player.update(random_engine);
        player.draw(window);
        window.display();
    }


    return 0;



}
