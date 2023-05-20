//
// Created by David on 5/20/2023.
//

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "Headers/Player.hpp"
#include "Headers/Global.hpp"


Player::Player() {

    reset();

    texture.loadFromFile("Resources/Temp-Player.png");
    sprite.setTexture(texture);

}

void Player::reset()
{
    dead = 0;

    x = 0.5f * (SCREEN_WIDTH - BASE_SIZE);
    y = SCREEN_HEIGHT - 2 * BASE_SIZE;

}


bool Player::get_dead() const {
    return dead;
}

unsigned short Player::get_y() const
{
    return y;
}