////
//// Created by David on 6/12/2023.
////
//#include "Headers/BonusEnemy.hpp"
//#include "Headers/Global.hpp"
//
//BonusEnemy::BonusEnemy(std::mt19937_64 &random_engine):
//        Entity(),
//        dead_animation_over(false),
//        explosion_x(0),
//        timer_distrib(0),
//animation = AnimationManager(
//        BONUS_ANIMATION_SPEED, 2 * BASE_SIZE, R"(C:\Users\40787\Desktop\PP-SPACE-INVASION\Source\Resources\BonusEnemy.png)");
//this->explosion = AnimationManager(
//        EXPLOSION_ANIMATION_SPEED, 2 * BASE_SIZE, R"(C:\Users\40787\Desktop\PP-SPACE-INVASION\Source\Resources\ExplosionBig.png)");
//
//
//{
//            this->y = BASE_SIZE;
//            this->powerup_distrib = std::uniform_int_distribution<unsigned short>(0, POWERUP_TYPES - 1);
//            this->timer_distrib = std::uniform_int_distribution<unsigned short>(BONUS_TIMER_MIN, BONUS_TIMER_MAX);
//            this->animation = AnimationManager(
//                    BONUS_ANIMATION_SPEED, 2 * BASE_SIZE, R"(C:\Users\40787\Desktop\PP-SPACE-INVASION\Source\Resources\BonusEnemy.png)");
//            this->explosion = AnimationManager(
//                    EXPLOSION_ANIMATION_SPEED, 2 * BASE_SIZE, R"(C:\Users\40787\Desktop\PP-SPACE-INVASION\Source\Resources\ExplosionBig.png)");
//
//            reset(true, random_engine);
////
////            for (unsigned char a = 0; a < POWERUP_TYPES; a++) {
////                powerup_animations.push_back(Animation(POWERUP_ANIMATION_SPEED, BASE_SIZE, "Resources/Images/Powerup" + std::to_string(static_cast<unsigned short>(a)) + ".png"));
////            }
//
//            this->powerup_animations.push_back(AnimationManager(POWERUP_ANIMATION_SPEED, BASE_SIZE,
//                                                         R"(C:\Users\40787\Desktop\PP-SPACE-INVASION\Source\Resources\BonusEnemy.png)"));
//        }
//
//
//
//


#include <random>

#include "Headers/AnimationManager.hpp"
#include "Headers/Global.hpp"
#include "Headers/BonusEnemy.hpp"
#include "Headers/Powerup.hpp"

BonusEnemy::BonusEnemy(std::mt19937_64& random_engine) :
        y(BASE_SIZE),
        powerup_distrib(0, POWERUP_TYPES - 1),
        timer_distrib(BONUS_TIMER_MIN, BONUS_TIMER_MAX),
        animation(BONUS_ANIMATION_SPEED, 2 * BASE_SIZE, R"(C:\Users\40787\Desktop\PP-SPACE-INVASION\Source\Resources\BonusEnemy.png)"),
        explosion(EXPLOSION_ANIMATION_SPEED, 2 * BASE_SIZE, R"(C:\Users\40787\Desktop\PP-SPACE-INVASION\Source\Resources\ExplosionBig.png)")
{
    reset(true, random_engine);

    for (unsigned char a = 0; a < POWERUP_TYPES; a++) {
        powerup_animations.push_back(AnimationManager(POWERUP_ANIMATION_SPEED, BASE_SIZE, R"(C:\Users\40787\Desktop\PP-SPACE-INVASION\Source\Resources\Powerup.png)"));
    }
}

bool BonusEnemy::check_bullet_collision(std::mt19937_64& i_random_engine, const sf::IntRect& bullet_hitbox) {
    if (0 == dead) {
        if (1 == get_hitbox().intersects(bullet_hitbox)) {
            dead = true;

            explosion_x = x;

            powerups.push_back(Powerup(x + 0.5f * BASE_SIZE, y, powerup_distrib(i_random_engine)));

            return true;
        }
    }

    return false;
}

unsigned char BonusEnemy::check_powerup_collision(const sf::IntRect& player_hitbox) {

    for (Powerup& powerup : powerups) {
        if (!powerup.dead && powerup.get_hitbox().intersects(player_hitbox)) {
            powerup.dead = true;

            // we add one because we have that offset
            return 1 + powerup.powerup_type;
        }
    }
    return 0;
}

void BonusEnemy::draw(sf::RenderWindow& window) {
    if (!dead) {
        animation.draw(x, y, window);
    }

    if (!dead_animation_over) {
        explosion.draw(explosion_x, y - 0.5f * BASE_SIZE, window, sf::Color(255, 36, 0));
    }

    for (Powerup& powerup : powerups) {
        powerup_animations[powerup.powerup_type].draw(powerup.x, powerup.y, window);
    }
}

void BonusEnemy::reset(bool dead, std::mt19937_64& random_engine) {
    dead = dead;
    dead_animation_over = false;

    explosion_x = SCREEN_WIDTH;
    x = SCREEN_WIDTH;

    timer = timer_distrib(random_engine);

    powerups.clear();

    animation.reset();
    explosion.reset();
}

void BonusEnemy::update(std::mt19937_64& random_engine) {
    if (!dead) {
        x -= BONUS_MOVE_SPEED;

        if (x <= -2 * BASE_SIZE) {
            dead = true;
        }

        animation.update();

    } else {
        if (!dead_animation_over) {
            dead_animation_over = explosion.update();
        }

        if (timer == 0) {
            reset(0, random_engine);
        } else {
            timer--;
        }
    }

    for (Powerup& powerup : powerups) {
        powerup.y += POWERUP_SPEED;

        if (SCREEN_HEIGHT <= powerup.y) {
            powerup.dead = true;
        }
    }

    for (AnimationManager& powerup_animation : powerup_animations) {
        powerup_animation.update();
    }

    powerups.erase(remove_if(powerups.begin(), powerups.end(), [](const Powerup& powerup) {
        return powerup.dead;
    }), powerups.end());
}

sf::IntRect BonusEnemy::get_hitbox() const {
    return sf::IntRect(x, y, 2 * BASE_SIZE, BASE_SIZE);
}