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

//    reset(0);

    this->enemy_bullet_texture.loadFromFile(R"(C:\Users\40787\Desktop\PP-SPACE-INVASION\Source\Resources\Enemy-Bullet-1.png)");
    this->enemy_bullet_sprite.setTexture(enemy_bullet_texture);

    std::string path = R"(C:\Users\40787\Desktop\PP-SPACE-INVASION\Source\Resources/Images/Enemy-1.png)";
    enemy_animations.emplace_back(1 + pause, BASE_SIZE, R"(C:\Users\40787\Desktop\PP-SPACE-INVASION\Source\Resources\Enemy1.png)");
}

bool EnemyManager::reached_player(unsigned short player_y) const {
    for (const Enemy& enemy: enemies) {
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
        for (unsigned char i=0; i < bullet.previous_x.size(); i++) {

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
        enemy_animations[enemy.get_enemy_type()].draw(enemy.get_x(), enemy.get_y(), window, enemy_color);
    }


}


void EnemyManager::reset(unsigned short i_level)
{
    //RESET EVERYTHING!!!!
    unsigned char enemy_x = 0;
    unsigned char enemy_y = 0;

    std::string level_sketch = "1 1 1 1 1 1 1 1 \n 1 1 1 1 1 1 1 1 \n 1 1 1 1 1 1 1 1";

    pause = std::max<short>(ENEMY_MOVE_PAUSE_START_MIN, ENEMY_MOVE_PAUSE_START - ENEMY_MOVE_PAUSE_DECREASE * i_level);
    move_timer = pause;

    shoot_distrib = std::uniform_int_distribution<unsigned short>(0, std::max<short>(ENEMY_SHOOT_CHANCE_MIN, ENEMY_SHOOT_CHANCE - ENEMY_SHOOT_CHANCE_INCREASE * i_level));

    for (AnimationManager& enemy_animation : enemy_animations)
    {
        enemy_animation.reset();
    }

    enemy_bullets.clear();

    enemies.clear();


    //Here we're converting each character into an enemy.
    for (char sketch_character : level_sketch)
    {
        enemy_x++;

        switch (sketch_character)
        {
            case '\n':
            {
                enemy_x = 0;
                enemy_y++;

                break;
            }
            case '0':
            {
                enemies.emplace_back(0, BASE_SIZE * (1 + enemy_x), BASE_SIZE * (2 + enemy_y));

                break;
            }
            case '1':
            {
                enemies.emplace_back(1, BASE_SIZE * (1 + enemy_x), BASE_SIZE * (2 + enemy_y));

                break;
            }
            case '2':
            {
                enemies.emplace_back(2, BASE_SIZE * (1 + enemy_x), BASE_SIZE * (2 + enemy_y));
            }
        }
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

void EnemyManager::update(std::mt19937_64& i_random_engine)
{
    std::vector<Enemy>::iterator dead_enemies_start;

    if (0 == move_timer)
    {
        move_timer = pause;

        for (Enemy& enemy : enemies)
        {
            enemy.move();
        }

        for (AnimationManager& enemy_animation : enemy_animations)
        {
            //The enemies change their frame after each move.
            enemy_animation.change_curr_frame();
        }
    }
    else
    {
        move_timer--;
    }

    for (Enemy& enemy : enemies)
    {
        enemy.update();

        if (0 == shoot_distrib(i_random_engine))
        {
            enemy.shoot(enemy_bullets);
        }
    }

    //I used a lambda!
    //I'm a pro!
    //No, not like that.
    //I'M A PROFESSIONAL C++ PROGRAMMER!!!!
    //Yeah, that's better.
    dead_enemies_start = remove_if(enemies.begin(), enemies.end(), [](const Enemy& i_enemy)
    {
        return 0 == i_enemy.get_health();
    });

    //The more enemies we kill, the faster they become.
    pause = std::max<int>(ENEMY_MOVE_PAUSE_MIN, pause - ENEMY_MOVE_PAUSE_DECREASE * (enemies.end() - dead_enemies_start));

    enemies.erase(dead_enemies_start, enemies.end());

    for (Bullet& enemy_bullet : enemy_bullets)
    {
        enemy_bullet.update();
    }

    //I used a lambda!
    //AGAIN!
    enemy_bullets.erase(remove_if(enemy_bullets.begin(), enemy_bullets.end(), [](const Bullet& i_bullet)
    {
        return 1 == i_bullet.dead;
    }), enemy_bullets.end());



}

std::vector<Bullet>& EnemyManager::get_enemy_bullets() {
    return enemy_bullets;
}

std::vector<Enemy>& EnemyManager::get_enemies() {
    return enemies;
}

