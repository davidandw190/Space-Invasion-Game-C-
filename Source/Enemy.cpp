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

unsigned char Enemy::get_health() const {
    return this->health;
}

unsigned char Enemy::get_hit_points() const {
    return this->hit_points;
}

unsigned char Enemy::get_hit_timer() const {
    return this->hit_timer;
}

unsigned short Enemy::get_enemy_type() const {
    return this->enemy_type;
}


void Enemy::hit() {
    this->hit_timer = ENEMY_HIT_TIMER_DURATION;
}

void Enemy::update() {
        if (this->hit_timer == 1)
            this->hit_points = std::max(0, hit_points - 1);

        this->hit_timer--;
}

void Enemy::move() {
    if (0 != this->direction) {
        if ((1 == direction && x == SCREEN_WIDTH - 2 * BASE_SIZE) || (-1 == direction && x == BASE_SIZE)) {
            //Moving downwards after reaching the edge
            this->direction = 0;

            this->y += ENEMY_MOVE_SPEED;
        } else {
            //Moving left and right
            this->x = std::clamp<short>(x + ENEMY_MOVE_SPEED * direction, BASE_SIZE, SCREEN_WIDTH - 2 * BASE_SIZE);
        }
    } else {
        this->y = std::min<short>(y + ENEMY_MOVE_SPEED, BASE_SIZE * ceil(y / static_cast<float>(BASE_SIZE)));

        if (this->y == BASE_SIZE * ceil(this->y / static_cast<float>(BASE_SIZE))) {
            //Checking which direction the enemy should move in
            this->direction = (this->y / BASE_SIZE) % 2 == 0 ? -1 : 1;
        }

    }
}

sf::IntRect Enemy::get_hitbox() const {
    return sf::IntRect(
            this->x + 0.25f * BASE_SIZE,
            this->y + 0.25f * BASE_SIZE,
            0.5f * BASE_SIZE,
            0.5f * BASE_SIZE);
}

void Enemy::shoot(std::vector<Bullet>& enemy_bullets) {
    enemy_bullets.push_back(Bullet(0, ENEMY_BULLET_SPEED, this->x, this->y));
}
