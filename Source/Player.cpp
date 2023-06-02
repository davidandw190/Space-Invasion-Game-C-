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
#include "Headers/Bullet.hpp"


Player::Player() : Entity() {
    reset(); // for when we transition to a new level etc., because we will cal again the constructor

    current_power = 0;
    reload_timer = 0;



    texture.loadFromFile(R"(C:\Users\40787\Desktop\PP-SPACE-INVASION\Source\Resources\Test-Player.png)");
    bullet_texture.loadFromFile(R"(C:\Users\40787\Desktop\PP-SPACE-INVASION\Source\Resources\Player-Bullet.png)");

    sprite.setTexture(texture);
    bullet_sprite.setTexture(bullet_texture);





}

void Player::reset() {
    dead = false;
    x = 0.5f * (SCREEN_WIDTH - BASE_SIZE);  // x and y position the player
    y = SCREEN_HEIGHT - 2 * BASE_SIZE;

    player_bullets.clear();

}


void Player::die() {
    dead = true;
}

void Player::draw(sf::RenderWindow& window) {
    if (!dead) {
        // Here we basically iterate over the player texture according to `the current_power` offset
        sprite.setTextureRect(
                sf::IntRect(BASE_SIZE * current_power, 0, BASE_SIZE, BASE_SIZE));

        // I set the position of the player's sprite as a vector since it does not accept actulat ints
        sprite.setPosition(sf::Vector2f(x, y));

        for (const Bullet& bullet : player_bullets)
        {
            bullet_sprite.setPosition(bullet.x, bullet.y);

            window.draw(bullet_sprite);
        }

        window.draw(sprite);

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

void Player::update(std::mt19937_64& random_engine) {
    if (!dead) {
        // move left
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            x = std::max<int>(x - PLAYER_MOVE_SPEED, BASE_SIZE);
        }

        // move right
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            x = std::min<int>(PLAYER_MOVE_SPEED + x, SCREEN_WIDTH - 2 * BASE_SIZE);
        }

        // player shoot
        if (reload_timer == 0) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
                // we will do interesting stuff here when we get to the power-ups
                reload_timer = RELOAD_DURATION;

                player_bullets.push_back(Bullet(0, -PLAYER_BULLET_SPEED, x, y));
            }




        } else {
            reload_timer--;
        }


    }

    for (Bullet& bullet : player_bullets)
    {
        bullet.update();

    }





}