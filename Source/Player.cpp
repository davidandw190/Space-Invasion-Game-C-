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

    texture.loadFromFile(R"(C:\Users\40787\Desktop\PP-SPACE-INVASION\Source\Resources\Test-Player.png)");
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
        //sprite.setPosition(x, y);   //this does not work, I have to fix it
        sprite.setTextureRect(
                sf::IntRect(BASE_SIZE * current_power, 0, BASE_SIZE, BASE_SIZE));

        window.draw(sprite);

    }
}

sf::IntRect Player::get_hitbox() const {
    return sf::IntRect(
            x + 0.125f * BASE_SIZE,
            y + 0.125f * BASE_SIZE,
            0.75f * BASE_SIZE,
            0.75f * BASE_SIZE
            );
}

void Player::update(std::mt19937_64& i_random_engine) {
    if (!dead) {
        if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            x = std::max<int>(x - PLAYER_MOVE_SPEED, BASE_SIZE);
        }

        if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            x = std::min<int>(PLAYER_MOVE_SPEED + x, SCREEN_WIDTH - 2 * BASE_SIZE);
        }
    }

}
