#pragma once
#include <SFML/Graphics.hpp>
#include "other/include/button.hpp"
#include <iostream>

namespace mine_other
{
    void SpriteButton::handleEvent(sf::Event event, sf::RenderWindow &window)
    {
        sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
        if(getGlobalBounds().contains(mouse_pos.x, mouse_pos.y))
        {
            if(event.type == sf::Event::MouseButtonReleased)
            {
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    _is_pressed_down = false;
                    parent -> call_parent_func("reset_game");
                    //std::cout << _is_pressed_down << "coc\n";
                }
            }
            if(event.type == sf::Event::MouseButtonPressed)
            {
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    _is_pressed_down = true;
                    //std::cout << _is_pressed_down << "cac\n";
                }
            }
        }
        else
        {
            _is_pressed_down = false;
            //parent ->call_parent_func("reset_game");
            //std::cout << _is_pressed_down << "coc\n";
        }
    }
}