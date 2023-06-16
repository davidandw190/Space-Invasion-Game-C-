//
// Created by tudor on 6/16/2023.
//
// Player2.cpp
//
//#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>
//#include <SFML/System.hpp>
//#include <random>
//
//#include "Headers/Player2.hpp"
//#include "Headers/Global.hpp"
//#include "Headers/Bullet.hpp"
//#include "Headers/Enemy.hpp"
//#include "Headers/BonusEnemy.hpp"
//
//Player2::Player2() : Entity(), explosion(EXPLOSION_ANIMATION_SPEED, BASE_SIZE,
//                                         R"(C:\Users\40787\Desktop\PP-SPACE-INVASION\Source\Resources\Explosion.png)") {
//    reset();
//
//    current_power = 0;
//    reload_timer = 0;
//
//    texture.loadFromFile(R"(C:\Users\40787\Desktop\PP-SPACE-INVASION\Source\Resources\Test-Player2.png)");
//    bullet_texture.loadFromFile(R"(C:\Users\40787\Desktop\PP-SPACE-INVASION\Source\Resources\Player-Bullet.png)");
//
//    sprite.setTexture(texture);
//    bullet_sprite.setTexture(bullet_texture);
//}
//
//void Player2::reset() {
//    this->current_power = 0;
//    this->reload_timer = 0;
//    this->dead_animation_over = false;
//    this->shield_animation_over = true;
//    this->power_timer = 0;
//
//    this->dead = false;
//    this->x = 0.5f * (SCREEN_WIDTH - BASE_SIZE);  // x and y position of the player
//    this->y = SCREEN_HEIGHT - 2 * BASE_SIZE;
//
//    this->player_bullets.clear();
//
//    this->explosion.reset();
//}
//
//void Player2::handleInput() {
//    if (!dead) {
//        // Handle input for the second player
//
//        // Move left
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
//            x = std::max<int>(x - PLAYER_MOVE_SPEED, BASE_SIZE);
//        }
//
//        // Move right
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
//            x = std::min<int>(PLAYER_MOVE_SPEED + x, SCREEN_WIDTH - 2 * BASE_SIZE);
//        }
//
//        // Shoot
//        if (reload_timer == 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
//            reload_timer = RELOAD_DURATION;
//            player_bullets.push_back(Bullet(0, -PLAYER_BULLET_SPEED, x, y));
//        } else {
//            reload_timer--;
//        }
//    }
//}
//
//void Player2::update(std::mt19937_64& random_engine,
//                     std::vector<Bullet>& enemy_bullets,
//                     std::vector<Enemy>& enemies,
//                     BonusEnemy& bonus_enemy) {
//    if (!dead) {
//
//        for (Bullet& bullet : enemy_bullets) {
//            if (this->get_hitbox().intersects(bullet.get_hitbox())) {
//                dead = true;
//                bullet.dead = true; // Kill the bullet
//
//                break;
//            }
//        }
//
//    } else if (!dead_animation_over) {
//        dead_animation_over = explosion.update();
//    }
//
//    for (Bullet& bullet : player_bullets) {
//        bullet.update();
//
//        if (!bullet.dead) {
//            if (bonus_enemy.check_bullet_collision(random_engine, bullet.get_hitbox())) {
//                bullet.dead = true;
//            }
//        }
//    }
//
//}
//
//void Player2::draw(sf::RenderWindow& window) {
//    if (!dead) {
//
//        sprite.setTextureRect(sf::IntRect(BASE_SIZE * current_power, 0, BASE_SIZE, BASE_SIZE));
//        sprite.setPosition(sf::Vector2f(x, y));
//
//        for (const Bullet& bullet : player_bullets) {
//            bullet_sprite.setPosition(bullet.x, bullet.y);
//            window.draw(bullet_sprite);
//        }
//
//        window.draw(sprite);
//
//        if (!shield_animation_over) {
//            explosion.draw(x, y, window, sf::Color(0, 109, 255));
//        }
//    } else if (!dead_animation_over) {
//        explosion.draw(x, y, window, sf::Color(255, 36, 0));
//    }
//}
//
//Other member function implementations...