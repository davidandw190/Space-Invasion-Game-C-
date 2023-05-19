#include <iostream>
#include <SFML/Graphics.hpp> // for display
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


#include <chrono>             // for timing
#include <random>
#include "Headers/Global.hpp"


int main() {

    std::chrono::microseconds lag(0);    // will use it to make the decuple the framerate and make it independent,
    std::chrono::steady_clock::time_point prev_time;    // will use it to compute the elapsed time

    std::mt19937_64 random_engine(
            std::chrono::system_clock::now().time_since_epoch().count()
    );

    sf::RenderWindow window(sf::VideoMode(SCREEN_RESIZE * SCREEN_WIDTH, SCREEN_RESIZE * SCREEN_HEIGHT),
                            "TEST-title-idk",
                            sf::Style::Close);

    window.setView(sf::View(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT)));

    sf::Sprite background_sprite;
    sf::Texture background_texture;

    background_texture.loadFromFile("Resources/Background.png");
    background_sprite.setTexture(background_texture);

    prev_time = std::chrono::steady_clock::now();

    while (window.isOpen())
    {
        sf::Event event{};

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }


    return 0;



}
