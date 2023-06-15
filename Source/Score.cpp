//
// Created by David on 6/15/2023.
//

#include "Headers/Score.hpp"

#include <iostream>

Score::Score()
        : enemies_shot(0),
          waves_survived(0),
          powerups_taken(0),
          shoot_accuracy(0)
{
}

void Score::incrementEnemiesShot() {
    enemies_shot++;
}

void Score::incrementWavesSurvived() {
    waves_survived++;
}

void Score::incrementPowerupsTaken() {
    powerups_taken++;
}

void Score::updateShootAccuracy(unsigned int totalShots, unsigned int hits) {
    if (totalShots > 0)
        shoot_accuracy = (hits * 100) / totalShots;
}

void Score::reset() {
    enemies_shot = 0;
    waves_survived = 0;
    powerups_taken = 0;
    shoot_accuracy = 0;
}

unsigned int Score::getEnemiesShot() const {
    return enemies_shot;
}

unsigned int Score::getWavesSurvived() const {
    return waves_survived;
}

unsigned int Score::getPowerupsTaken() const {
    return powerups_taken;
}

unsigned int Score::getShootAccuracy() const {
    return shoot_accuracy;
}