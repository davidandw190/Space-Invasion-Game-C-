//
// Created by David on 5/18/2023.
//
#pragma once

#ifndef PP_SPACE_INVASION_GLOBAL_H
#define PP_SPACE_INVASION_GLOBAL_H

#endif

#include <cmath>
#include <chrono>


// a base size that will be used as point of reference for textures and sizes
constexpr unsigned char BASE_SIZE = 16;

// required when drawing the window
constexpr unsigned char SCREEN_RESIZE = 4;
constexpr unsigned short SCREEN_HEIGHT = 180;
constexpr unsigned short SCREEN_WIDTH = 320;

// player related stuff
constexpr unsigned char PLAYER_MOVE_SPEED = 2;
constexpr unsigned char PLAYER_BULLET_SPEED = 4;
constexpr unsigned char RELOAD_DURATION = 30;
constexpr unsigned char FAST_RELOAD_DURATION = 6;

// Enemy related stuff
constexpr unsigned char ENEMY_HIT_TIMER_DURATION = 1;
constexpr unsigned char ENEMY_MOVE_SPEED = 1;

constexpr unsigned char ENEMY_BULLET_SPEED = 2;

constexpr unsigned short ENEMY_SHOOT_CHANCE = 2080;

// a constant for the frame duration in ms
constexpr std::chrono::microseconds FRAME_DURATION(16667);

