//
// Created by Gabriel on 5/20/2023.
//
#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <random>

#ifndef PP_SPACE_INVASION_ENEMY_H
#define PP_SPACE_INVASION_ENEMY_H

#endif //PP_SPACE_INVASION_ENEMY_H

class Enemy{
private:
    short direction; //-1 left, +1 right, 0 down

    unsigned short enemy_type;
    unsigned char hit_points;
    unsigned char hit_timer;
    unsigned short x;
    unsigned short y;

public:
    Enemy(unsigned short i_enemy_type, unsigned short i_x, unsigned short i_y);

    unsigned char get_hit_points() const;
    unsigned char get_hit_timer() const;
    unsigned short get_enemy_type() const;
    unsigned short get_x() const;
    unsigned short get_y() const;

    void move();
    void hit();
    void shoot(std::vector<Bullet>& i_EnemyBullets);
    void update();

    sf::IntRect get_hitbox() const;
};
