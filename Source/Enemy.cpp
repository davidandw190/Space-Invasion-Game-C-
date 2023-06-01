//
// Created by Gabriel on 5/24/2023.
//

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <random>
#include <chrono>

#include "Headers/Enemy.hpp"
#include "Headers/Global.hpp"

Enemy::Enemy(unsigned char type, unsigned short x, unsigned short y)
    :Entity(),
     direction(0 == (y / BASE_SIZE) % 2 ? -1 : 1),
     health(1 + type),
     hit_timer(0),
     hit_points(0),
     enemy_type(type)
{
    this->x = x;
    this->y = y;
}

unsigned char Enemy::get_hit_points() const {

}

unsigned char Enemy::get_hit_timer() const {

}

unsigned short Enemy::get_enemy_type() const {

}


void Enemy::move() {

}

void Enemy::hit() {

}

void Enemy::update() {

}

void Enemy::shoot() {

}

sf::IntRect Enemy::get_hitbox() const {

}

void Enemy::shoot(std::vector<Bullet> &EnemyBullets) {

}
