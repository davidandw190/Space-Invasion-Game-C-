//
// Created by David on 6/15/2023.
//

#ifndef PP_SPACE_INVASION_SCORE_HPP
#define PP_SPACE_INVASION_SCORE_HPP

#include <string>

class Score {
private:
    unsigned int enemies_shot;
    unsigned int waves_survived;
    unsigned int powerups_taken;
    unsigned int shoot_accuracy;

public:
    Score();

    void incrementEnemiesShot();
    void incrementWavesSurvived();
    void incrementPowerupsTaken();
    void updateShootAccuracy(unsigned int totalShots, unsigned int hits);
    void reset();

    unsigned int getEnemiesShot() const;
    unsigned int getWavesSurvived() const;
    unsigned int getPowerupsTaken() const;
    unsigned int getShootAccuracy() const;
};
#endif //PP_SPACE_INVASION_SCORE_HPP

