//
// Created by David on 6/10/2023.
//


#include <SFML/Graphics/Rect.hpp>
#include "Headers/Global.hpp"


struct Powerup {

    bool dead;
    short x;
    short y;

    //1 - mirrored controls
    //2 - fast reload
    //3 - shotgun bullets
    //4 - shield
    unsigned char powerup_type;

    Powerup(short x, short y, unsigned char powerup_type)
            :dead(0),
            x(x),
            y(y),
            powerup_type(powerup_type) { }

    sf::IntRect get_hitbox() const {
        return sf::IntRect(x + 0.25f * BASE_SIZE,
                           y + 0.25f * BASE_SIZE,
                           0.5f * BASE_SIZE,
                           0.5f * BASE_SIZE);
    }
};