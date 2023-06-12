//
// Created by David on 6/12/2023.
//

#include "Entity.hpp"
#include "AnimationManager.hpp"
#include "Powerup.hpp"

#ifndef PP_SPACE_INVASION_BONUSENEMY_HPP
#define PP_SPACE_INVASION_BONUSENEMY_HPP

class BonusEnemy: public Entity {

private:
    bool dead;
    bool dead_animation_over;

    short explosion_x;

    std::uniform_int_distribution<unsigned short> powerup_distrib;

    std::uniform_int_distribution<unsigned short> timer_distrib;

    std::vector<AnimationManager> powerup_animations;

    std::vector<Powerup> powerups;

    AnimationManager animation;
    AnimationManager explosion;

};


#endif //PP_SPACE_INVASION_BONUSENEMY_HPP
