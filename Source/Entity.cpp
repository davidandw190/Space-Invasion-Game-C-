//
// Created by 40787 on 5/21/2023.
//

#include "Headers/Entity.hpp"
#include <random>


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




