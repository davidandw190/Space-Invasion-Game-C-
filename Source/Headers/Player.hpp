//
// Created by David on 5/19/2023.
//

#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <random>

#ifndef PP_SPACE_INVASION_PLAYER_HPP
#define PP_SPACE_INVASION_PLAYER_HPP

#endif //PP_SPACE_INVASION_PLAYER_HPP

class Player {

    private:
        unsigned short x;
        unsigned short y;

        unsigned char reload_timer;

        bool dead;
        bool dead_animation_over;
        bool shield_animation_over;

    public:
        Player(); // the constructor. because we put pragama once at the to
                  // this will only be executed once(till we begin multiplayer)

        bool get_dead() const;
        bool get_dead_animation_over() const;

        unsigned short get_y() const;

        void die();
        void draw(sf::RenderWindow& i_window);
        void reset();
        void update(std::mt19937_64& i_random_engine, std::vector<Bullet>& i_enemy_bullets, std::vector<Enemy>& i_enemies, Ufo& i_ufo);

        sf::IntRect get_hitbox() const;


};