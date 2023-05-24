//
// Created by David on 5/19/2023.
//

#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <random>
#include "Entity.hpp"

#ifndef PP_SPACE_INVASION_PLAYER_HPP
#define PP_SPACE_INVASION_PLAYER_HPP

#endif //PP_SPACE_INVASION_PLAYER_HPP



class Player: public Entity {

    private:
        unsigned short x{};
        unsigned short y{};

        sf::Sprite sprite;
        sf::Texture texture;

        unsigned char current_power;
        unsigned char reload_timer;

        bool dead{};

    public:
        Player();

        bool get_dead() const;
        bool get_dead_animation_over() const;


        void die();
        void draw(sf::RenderWindow& window) override;

        void reset();
        void update(std::mt19937_64& i_random_engine) override;

        sf::IntRect get_hitbox() const override;  // will be used for collision detection



};