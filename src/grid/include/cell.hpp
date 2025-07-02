#pragma once
#include <SFML/Graphics.hpp>
#include "core/include/object.hpp"

//Will be rewritten!!! No use now!!!
namespace mine_grid
{
    //Cell position is relative to grid
    class Cell : private mine_core::SpriteObject
    {
    private:
        sf::Vector2i _grid_position;

        bool _is_opened;
        bool _has_mine;
    public:
        Cell();
        ~Cell();

        unsigned short neighbor_mines();

        void on_lmb_release();
    };
}