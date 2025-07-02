#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "core/include/object.hpp"
#include "cell.hpp"

namespace mine_grid
{
    /*
    class SpriteObject : public sf::Sprite
    {
    public:
        SpriteObject(const sf::Vector2f& position);
        ~SpriteObject();

        virtual void handleEvent(sf::Event event, sf::RenderWindow &window){}
        virtual void update(float deltaTime){}
    };
    */
    class Grid : public mine_core::SpriteObject
    {
    private:
        std::vector<std::vector<mine_grid::Cell>> _grid;
    public:
        Grid(unsigned short gridWidth, unsigned short gridHeight);
        ~Grid();


    };
}