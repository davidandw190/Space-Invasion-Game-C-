//
// Created by David on 5/19/2023.
//

#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <random>
#include "AnimationManager.hpp"
#include "Entity.hpp"
#include "Bullet.hpp"
#include "Enemy.hpp"
#include "BonusEnemy.hpp"

#ifndef PLAYER_HPP
#define PLAYER_HPP


class Player : public Entity {
private:
    bool dead;
    bool dead_animation_over;
    bool shield_animation_over;

    unsigned char current_power;
    unsigned char reload_timer;
    unsigned short power_timer;

    sf::Sprite bullet_sprite;
    sf::Texture bullet_texture;

    std::vector<Bullet> player_bullets;

    AnimationManager explosion;

public:
    Player();
    virtual void reset();
    virtual void die();
    sf::IntRect get_hitbox() const override;
    virtual void draw(sf::RenderWindow& window);
    virtual void update(std::mt19937_64& random_engine, std::vector<Bullet>& enemy_bullets, std::vector<Enemy>& enemies, BonusEnemy& bonus_enemy);

    bool get_dead_animation_over() const;
    unsigned char get_current_power() const;
    unsigned short get_power_timer() const;
};



#endif // PLAYER_HPP


