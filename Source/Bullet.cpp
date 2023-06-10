//
// Created by David on 5/24/2023.
//

#include "Headers/Bullet.hpp"
#include "Headers/Global.hpp"
#include <cmath>
#include <SFML/Graphics/Rect.hpp>

Bullet::Bullet(float step_x, float step_y, short x, short y)
        : dead(false), // the bullet, not the player
          real_x(x),
          real_y(y),
          step_x(step_x),
          step_y(step_y),
          x(x),
          y(y) {

    previous_x.fill(x);
    previous_y.fill(y);
}

void Bullet::update() {
    if (!dead) {
        real_x += step_x;
        real_y += step_y;

        for (unsigned char a = 0; a < previous_x.size() - 1; a++) {
            previous_x[a] = previous_x[1 + a];
            previous_y[a] = previous_y[1 + a];
        }

        previous_x[previous_x.size() - 1] = x;
        previous_y[previous_y.size() - 1] = y;

        // for accuracy, it rounds the bullets from float to short bcz computers are not great at floats
        x = std::round(real_x);
        y = std::round(real_y);


        // this is important. it checks weather the bullet is in the screen zone,
        // if not the case, it "kills" the bullet
        if (x <= -BASE_SIZE || y <= -BASE_SIZE || SCREEN_HEIGHT <= y || SCREEN_WIDTH <= x){
            dead = true;
        }
    }
}

// again, for collision detection of the rectangle of the bullet
sf::IntRect Bullet::get_hitbox() const {
    return sf::IntRect(x + 0.375f * BASE_SIZE, y + 0.375f * BASE_SIZE, 0.25f * BASE_SIZE, 0.25f * BASE_SIZE);
}

