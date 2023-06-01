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
    unsigned char current_power;
    unsigned char reload_timer;

    bool dead{};

public:
    Player();

    void reset();
    void die();
    void draw(sf::RenderWindow& window) override;
    void update(std::mt19937_64& random_engine) override;
    sf::IntRect get_hitbox() const override;  // will be used for collision detection

};