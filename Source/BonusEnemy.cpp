////
//// Created by David on 6/12/2023.
////
//#include "Headers/BonusEnemy.hpp"
//#include "Headers/Global.hpp"
//
//BonusEnemy::BonusEnemy(std::mt19937_64 &random_engine):
//        Entity(),
//        dead_animation_over(false),
//        explosion_x(0),
//        timer_distrib(0)
//
//        {
//            this->y = BASE_SIZE;
//            this->powerup_distrib = std::uniform_int_distribution<unsigned short>(0, POWERUP_TYPES - 1);
//            this->timer_distrib = std::uniform_int_distribution<unsigned short>(BONUS_TIMER_MIN, BONUS_TIMER_MAX);
//            this->animation = AnimationManager(
//                    BONUS_ANIMATION_SPEED, 2 * BASE_SIZE, R"(C:\Users\40787\Desktop\PP-SPACE-INVASION\Source\Resources\BonusEnemy.png)");
//            this->explosion = AnimationManager(
//                    EXPLOSION_ANIMATION_SPEED, 2 * BASE_SIZE, R"(C:\Users\40787\Desktop\PP-SPACE-INVASION\Source\Resources\ExplosionBig.png)");
//
//            reset(true, random_engine);
////
////            for (unsigned char a = 0; a < POWERUP_TYPES; a++) {
////                powerup_animations.push_back(Animation(POWERUP_ANIMATION_SPEED, BASE_SIZE, "Resources/Images/Powerup" + std::to_string(static_cast<unsigned short>(a)) + ".png"));
////            }
//
//            this->powerup_animations.push_back(AnimationManager(POWERUP_ANIMATION_SPEED, BASE_SIZE,
//                                                         R"(C:\Users\40787\Desktop\PP-SPACE-INVASION\Source\Resources\BonusEnemy.png)"));
//        }
//
//
//
//
