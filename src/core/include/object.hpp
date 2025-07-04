#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

//Namespace for all core features. It could be used for any application.
namespace mine_core
{
    class SpriteObject : public sf::Sprite
    {
    protected:
        //I need this field to make sure that assigned texture will stay with sprite
        sf::Texture _texture;
    public:
        SpriteObject* parent;
        //Don't redefine constructors and destructors, too dangerous
        //SpriteObject();
        //~SpriteObject();
        void setTexture(const sf::Texture &texture, bool resetRect = false)
        {
            _texture = texture;
            sf::Sprite::setTexture(_texture, resetRect);
        }
        virtual void call_parent_func(std::string func, sf::Vector2i auto_open_arg = sf::Vector2i(0,0)){}

        virtual void handleEvent(sf::Event event, sf::RenderWindow &window){}
        virtual void update(float deltaTime){}
        virtual void render(sf::RenderWindow &window)
        {
            window.draw(*this);
        }
    };
}