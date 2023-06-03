//
// Created by David on 6/3/2023.
//

#pragma once

#ifndef PP_SPACE_INVASION_ANIMATIONMANAGER_HPP
#define PP_SPACE_INVASION_ANIMATIONMANAGER_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class AnimationManager {
    //When this iterator reaches the animation speed, we change the frame and reset the iterator.
    unsigned short animation_iterator;
    //The higher the value, the slower the animation.
    unsigned short animation_speed;
    unsigned short curr_frame;
    //To make things easier, each image file will contain 1 animation. So that the frame heights are the same.
    unsigned short frame_width;
    //We can find this by dividing the width of the image by the frame width.
    unsigned short total_frames;

    sf::Sprite sprite;

    sf::Texture texture;
public:
    AnimationManager(unsigned short animation_speed, unsigned short frame_width, const std::string& texture_location);

    bool change_curr_frame();
    bool update();

    void draw(short x, short y, sf::RenderWindow& window, const sf::Color& color = sf::Color(255, 255, 255));
    void reset();
};



#endif //PP_SPACE_INVASION_ANIMATIONMANAGER_HPP
