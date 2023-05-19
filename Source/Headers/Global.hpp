//
// Created by David on 5/18/2023.
//
#pragma once

#ifndef PP_SPACE_INVASION_GLOBAL_H
#define PP_SPACE_INVASION_GLOBAL_H

#endif

// a base size that will be used as point of reference for all other sizes
constexpr unsigned char BASE_SIZE = 16;

// required when drawing the window
constexpr unsigned char SCREEN_RESIZE = 4;
constexpr unsigned short SCREEN_HEIGHT = 180;
constexpr unsigned short SCREEN_WIDTH = 320;

// player related stuff
constexpr unsigned char PLAYER_MOVE_SPEED = 2;

// a constant for the frame duration in ms
constexpr std::chrono::microseconds FRAME_DURATION(16667);
