//
// Created by David on 5/20/2023.
//

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <random>
#include <chrono>

#include "Headers/Player.hpp"
#include "Headers/Global.hpp"



Player::Player() : Entity() {

    reset(); // for when we transition to a new level etc., because we will cal again the constructor

    current_power = 0;

    texture.loadFromFile("Resources/Test-Player.png");
    sprite.setTexture(texture);

}

void Player::reset() {
    dead = false;

    x = 0.5f * (SCREEN_WIDTH - BASE_SIZE);  // x and y position the player
    y = SCREEN_HEIGHT - 2 * BASE_SIZE;

}

bool Player::get_dead() const {
    return dead;
}

void Player::die() {
    dead = true;
}

void Player::draw(sf::RenderWindow& window) {
    if (!dead) {
        //sprite.setPosition(x, y);   //this does not work
        sprite.setTextureRect(
                sf::IntRect(BASE_SIZE * current_power, 0, BASE_SIZE, BASE_SIZE));

        window.draw(sprite);

    }
}

sf::IntRect Player::get_hitbox() const {  // this is the same as writing return sf::IntRect
    return {};
}
