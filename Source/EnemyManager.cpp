//
// Created by David on 6/3/2023.
//


#include <array>
#include <chrono>
#include <random>
#include <SFML/Graphics.hpp>


#include "Headers/Global.hpp"
#include "Headers/Enemy.hpp"
#include "Headers/EnemyManager.hpp"


EnemyManager::EnemyManager(): shoot_distrib(0, ENEMY_SHOOT_CHANCE) {

    this->enemy_bullet_texture.loadFromFile(R"(C:\Users\40787\Desktop\PP-SPACE-INVASION\Source\Resources\Enemy-Bullet-1.png)");
    this->enemy_bullet_sprite.setTexture(enemy_bullet_texture);

    std::string path = R"(C:\Users\40787\Desktop\PP-SPACE-INVASION\Source\Resources/Images/Enemy-1.png)";
    enemy_animations.push_back(AnimationManager(1 + pause, BASE_SIZE, R"(C:\Users\40787\Desktop\PP-SPACE-INVASION\Source\Resources\Enemy-1.png)"));
}

bool EnemyManager::reached_player(unsigned short player_y) const {
    for (const Enemy& enemy: this->enemies) {
        if (enemy.get_y() > player_y - 0.5f * BASE_SIZE) {
            // we will make this end the game
            return true;
        }
    }
    return false;
}

void EnemyManager::draw(sf::RenderWindow& window) {

    for (const Bullet& bullet : this->enemy_bullets) {

        // drawing a trail effect for the bullet
        for (unsigned char i=0; i<bullet.previous_x.size(); i++) {

            enemy_bullet_sprite.setPosition(bullet.previous_x[i], bullet.previous_y[i]);
            enemy_bullet_sprite.setTextureRect(
                    sf::IntRect(BASE_SIZE * i, 0, BASE_SIZE, BASE_SIZE));

            window.draw(enemy_bullet_sprite);

        }

        // drawing the actual bullet
        enemy_bullet_sprite.setPosition(bullet.x, bullet.y);
        enemy_bullet_sprite.setTextureRect(sf::IntRect(BASE_SIZE * bullet.previous_x.size(), 0, BASE_SIZE, BASE_SIZE));

        window.draw(enemy_bullet_sprite);
    }

    for (Enemy& enemy : enemies) {
        // when the enemy gets hit, it's gonna appear white.
        sf::Color enemy_color = sf::Color(255, 255, 255);
        enemy_animations[0].draw(enemy.get_x(), enemy.get_y(), window, enemy_color);
    }


}

bool isBulletDead(const Bullet& i_bullet)
{
    return 1 == i_bullet.dead;
}

void removeDeadBullets(std::vector<Bullet>& enemy_bullets)
{
    enemy_bullets.erase(std::remove_if(enemy_bullets.begin(), enemy_bullets.end(), isBulletDead), enemy_bullets.end());
}

void EnemyManager::update(std::mt19937_64& random_engine)
{
    std::vector<Enemy>::iterator dead_enemies_start;

    if (0 == move_timer)
    {
        move_timer = pause;

        for (Enemy& enemy : enemies)
        {
            enemy.move();
        }
    }
    else
    {
        move_timer--;
    }

    for (Enemy& enemy : enemies)
    {
        enemy.update();

        if (0 == shoot_distrib(random_engine))
        {
            enemy.shoot(enemy_bullets);
        }
    }

    enemies.erase(dead_enemies_start, enemies.end());

    for (Bullet& enemy_bullet : enemy_bullets)
    {
        enemy_bullet.update();
    }

    removeDeadBullets(enemy_bullets);
}


std::vector<Bullet>& EnemyManager::get_enemy_bullets() {
    return enemy_bullets;
}

std::vector<Enemy>& EnemyManager::get_enemies() {
    return enemies;
}