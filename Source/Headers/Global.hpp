//
// Created by David on 5/18/2023.
//
#pragma once

#ifndef PP_SPACE_INVASION_GLOBAL_H
#define PP_SPACE_INVASION_GLOBAL_H



#include <cmath>
#include <chrono>


// a base size that will be used as point of reference for textures and sizes
constexpr unsigned char BASE_SIZE = 16;

// required when drawing the window
constexpr unsigned char SCREEN_RESIZE = 4;
constexpr unsigned short SCREEN_HEIGHT = 180;
constexpr unsigned short SCREEN_WIDTH = 320;
constexpr unsigned char NEXT_WAVE_TRANSITION = 64;
constexpr unsigned char TOTAL_WAVES = 8;

// player related stuff
constexpr unsigned char PLAYER_MOVE_SPEED = 2;
constexpr unsigned char PLAYER_BULLET_SPEED = 4;
constexpr unsigned char RELOAD_DURATION = 30;
constexpr unsigned char FAST_RELOAD_DURATION = 6;

// Enemy related stuff
constexpr unsigned char ENEMY_TYPES = 3;
constexpr unsigned char ENEMY_HIT_TIMER_DURATION = 2;
constexpr unsigned char ENEMY_MOVE_PAUSE_MIN = 3;
constexpr unsigned short ENEMY_SHOOT_CHANCE_INCREASE = 64;
constexpr unsigned short ENEMY_SHOOT_CHANCE_MIN = 1024;
constexpr unsigned char ENEMY_MOVE_SPEED = 3;

constexpr unsigned char ENEMY_MOVE_PAUSE_START = 63;
constexpr unsigned char ENEMY_MOVE_PAUSE_START_MIN = 47;
// the more enemies we kill, the faster they become.
constexpr unsigned char ENEMY_MOVE_PAUSE_DECREASE = 1;
constexpr unsigned char ENEMY_BULLET_SPEED = 2;
constexpr unsigned short ENEMY_SHOOT_CHANCE = 4500;

// bonus enemy stuff
constexpr unsigned char BONUS_ANIMATION_SPEED = 8;
constexpr unsigned char BONUS_MOVE_SPEED = 1;
constexpr unsigned short BONUS_TIMER_MAX = 1300;
constexpr unsigned short BONUS_TIMER_MIN = 768;

constexpr unsigned char EXPLOSION_ANIMATION_SPEED = 2;

constexpr unsigned short POWERUP_DURATION = 512;
constexpr unsigned char POWERUP_ANIMATION_SPEED = 16;
constexpr unsigned char POWERUP_SPEED = 2;
constexpr unsigned char POWERUP_TYPES = 4;


// player2 related stuff
//constexpr unsigned char PLAYER2_MOVE_SPEED = 2;
//constexpr unsigned char PLAYER2_BULLET_SPEED = 4;
//constexpr unsigned char RELOAD2_DURATION = 30;
//constexpr unsigned char FAST_RELOAD2_DURATION = 6;

// a constant for the frame duration in ms
constexpr std::chrono::microseconds FRAME_DURATION(16667);

#endif //PP_SPACE_INVASION_GLOBAL_H