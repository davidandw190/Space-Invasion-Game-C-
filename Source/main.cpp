#include <iostream>
#include <SFML/Graphics.hpp> // for display
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


#include <chrono>             // for timing
#include <random>
#include "Headers/Global.h"


int main() {

    std::chrono::microseconds lag(0);
    std::chrono::steady_clock::time_point prev_time;

    std::mt19937_64 random_engine(
            std::chrono::system_clock::now().time_since_epoch().count()
    );

    sf::RenderWindow window(sf::VideoMode(SCREEN_RESIZE * SCREEN_WIDTH, SCREEN_RESIZE * SCREEN_HEIGHT),
                            "TEST-title-idk",
                            sf::Style::Close);

    window.setView(sf::View(sf::FloatRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT)));


    window.display();


    return 0;
}
