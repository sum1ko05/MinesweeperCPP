#pragma once
#include <SFML/Graphics.hpp>
#include "core/include/object.hpp"

//Namespace for everything with grid. It's Minesweeper specific, so copy with caution.
namespace mine_grid
{
    class Cell : public mine_core::SpriteObject
    {
    private:
        //Cell position is relative to grid
        sf::Vector2i _grid_position;

        bool _is_opened;
        bool _has_mine;
    public:
        Cell(const sf::Vector2i &grid_position);
        ~Cell();

        sf::Vector2i getGridPosition()
        {
            return _grid_position;
        }

        unsigned short neighbor_mines();
        void open_cell();

        void on_lmb_release();
    };
}