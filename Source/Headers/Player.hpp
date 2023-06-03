//
// Created by David on 5/19/2023.
//

#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <random>
#include "Entity.hpp"
#include "Bullet.hpp"
#include "Enemy.hpp"

#ifndef PP_SPACE_INVASION_PLAYER_HPP
#define PP_SPACE_INVASION_PLAYER_HPP

#endif //PP_SPACE_INVASION_PLAYER_HPP



class Player: public Entity {

private:
    bool dead{};

    unsigned char current_power;
    unsigned char reload_timer;

    sf::Sprite bullet_sprite;
    sf::Texture bullet_texture;

    std::vector<Bullet> player_bullets;

public:
    Player();

    void reset();
    void die();

    sf::IntRect get_hitbox() const override;  // will be used for collision detection


    void draw(sf::RenderWindow &window);

    void update(std::mt19937_64 &random_engine, std::vector<Bullet> &enemy_bullets, std::vector<Enemy> &enemies);
};