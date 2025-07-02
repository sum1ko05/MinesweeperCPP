#pragma once
#include <SFML/Graphics.hpp>

//Basically, it's a sprite with additional functionality
namespace mine_core
{
    class SpriteObject : public sf::Sprite
    {
    private:
        //I need this field to make sure that assigned texture will stay with sprite
        sf::Texture _texture;
    public:
        //Don't redefine constructors and destructors, too dangerous
        //SpriteObject();
        //~SpriteObject();
        void setTexture(const sf::Texture &texture, bool resetRect = false)
        {
            _texture = texture;
            sf::Sprite::setTexture(_texture, resetRect);
        }

        virtual void handleEvent(sf::Event event, sf::RenderWindow &window){}
        virtual void update(float deltaTime){}
    };
}