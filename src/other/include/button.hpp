#pragma once
#include <SFML/Graphics.hpp>
#include "core/include/object.hpp"
#include <iostream>
#define ushort unsigned short

namespace mine_other
{
    class SpriteButton : public mine_core::SpriteObject
    {
    private:
        bool _is_pressed_down;
    protected:
        sf::Texture _texture_pressed;
        sf::Texture _texture_released;
    public:
        //SpriteButton();
        //~SpriteButton();

        void setReleasedTexture(const sf::Texture &texture, bool resetRect = false)
        {
            _texture_released = texture;
            //sf::Sprite::setTexture(_texture, resetRect);
        }
        void setPressedTexture(const sf::Texture &texture, bool resetRect = false)
        {
            _texture_pressed = texture;
            //sf::Sprite::setTexture(_texture, resetRect);
        }

        void handleEvent(sf::Event event, sf::RenderWindow &window) override;
        void render(sf::RenderWindow &window) override
        {
            if(_is_pressed_down) setTexture(_texture_pressed);
            else setTexture(_texture_released);
            window.draw(*this);
        };
    };
}