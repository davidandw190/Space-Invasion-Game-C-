//#pragma once
//
//#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>
//#include <SFML/System.hpp>
//#include <random>
//#include "Bullet.hpp"
//#include "Enemy.hpp"
//#include "BonusEnemy.hpp"
//#include "Entity.hpp"
//#include "Global.hpp"
//
//class Player2 : public Entity {
//private:
//    bool dead;
//    bool dead_animation_over;
//    bool shield_animation_over;
//
//    unsigned char current_power;
//    unsigned char reload_timer;
//    unsigned short power_timer;
//
//    sf::Sprite bullet_sprite;
//    sf::Texture bullet_texture;
//
//    std::vector<Bullet> player_bullets;
//
//    AnimationManager explosion;
//
//public:
//    Player2();
//    void reset();
//    void handleInput();
//    void update(std::mt19937_64& random_engine, std::vector<Bullet>& enemy_bullets, std::vector<Enemy>& enemies, BonusEnemy& bonus_enemy);
//    void draw(sf::RenderWindow& window);
//
//    sf::IntRect get_hitbox() const;
//    bool get_dead_animation_over() const;
//    unsigned char get_current_power() const;
//    unsigned short get_power_timer() const;
//};