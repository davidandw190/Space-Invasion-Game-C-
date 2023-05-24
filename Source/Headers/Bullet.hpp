//
// Created by David on 5/22/2023.
//

#ifndef PP_SPACE_INVASION_BULLET_HPP
#define PP_SPACE_INVASION_BULLET_HPP

#endif //PP_SPACE_INVASION_BULLET_HPP


#ifndef BULLET_HPP
#define BULLET_HPP

#include <SFML/Graphics.hpp>
#include <array>

struct Bullet {
    bool dead;

    float real_x;
    float real_y;
    float step_x;
    float step_y;

    short x;
    short y;

    std::array<short, 3> previous_x;
    std::array<short, 3> previous_y;

    Bullet(float i_step_x, float i_step_y, short i_x, short i_y);

    void update();

    sf::IntRect get_hitbox() const;
};

#endif
