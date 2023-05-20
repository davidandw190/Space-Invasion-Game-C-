//
// Created by David on 5/20/2023.
//

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <random>
#include <chrono>
#include <adomd.h>


#include "Headers/Player.hpp"
#include "Headers/Global.hpp"


Player::Player() {

    reset(); // for when we transition to a new level and etc, because we will cal again the constructor

    current_power = 0;

    texture.loadFromFile("Resources/Test-Player.png");
    sprite.setTexture(texture);

}

void Player::reset() {
    dead = 0;

    x = 0.5f * (SCREEN_WIDTH - BASE_SIZE);  // x and y position the player
    y = SCREEN_HEIGHT - 2 * BASE_SIZE;

}


bool Player::get_dead() const {
    return dead;
}

unsigned short Player::get_y() const {
    return y;
}

void Player::die() {
    dead = 1;
}

void Player::draw(sf::RenderWindow& window) {
    if (!dead) {
//        sprite.setPosition(x, y);   //this does not work
        sprite.setTextureRect(sf::IntRect(BASE_SIZE * current_power, 0, BASE_SIZE, BASE_SIZE));

        window.draw(sprite);

    }
}
