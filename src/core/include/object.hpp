#pragma once
#include <SFML/Graphics.hpp>

//Will be rewritten!!! No use now!!!
namespace mine_core
{
    class DrawableObject
    {
    protected:
        sf::Vector2f _position;
        sf::Color _color;
        bool _isVisible;

    public:
        DrawableObject(const sf::Vector2f& position, const sf::Color& color = sf::Color::White);

        void setPosition(const sf::Vector2f& pos) { _position = pos; }
        sf::Vector2f getPosition() const { return _position; }

        virtual void draw(sf::RenderWindow& window){
            if (!_isVisible) 
                return;
        }
        virtual void update(float deltaTime){}
    }

    class SpriteObject : public DrawableObject
    {
    private:
        sf::Sprite _sprite;
        sf::Texture _texture;

    public:
        SpriteObject(const sf::Vector2f& position, const std::string& texturePath) : DrawableObject(position){
            _texture.loadFromFile(texturePath);
            _sprite.setTexture(_texture);
            _sprite.setPosition(position);
        }

        void setPosition(const sf::Vector2f& pos) { _position = pos; }
        sf::Vector2f getPosition() const { return _position; }

        void draw(sf::RenderWindow& window) override {
            if (!_isVisible) return;
                window.draw(_sprite);
        }
    }
}