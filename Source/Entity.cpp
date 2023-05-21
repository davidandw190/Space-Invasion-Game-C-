//
// Created by 40787 on 5/21/2023.
//

#include "Headers/Entity.hpp"

Entity::Entity() = default;

bool Entity::get_dead() const {
    return dead;
}

unsigned short Entity::get_x() const {
    return x;
}

unsigned short Entity::get_y() const {
    return y;
}

void Entity::draw(sf::RenderWindow& window) {
    if (0 == dead) {
        sprite.setPosition(x, y);
        window.draw(sprite);
    }

}
