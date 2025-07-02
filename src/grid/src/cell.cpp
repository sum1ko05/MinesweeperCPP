#include "grid/include/cell.hpp"
#include <SFML/Graphics.hpp>
#include "core/include/object.hpp"
#define ushort unsigned short

//Namespace for everything with grid. It's Minesweeper specific, so copy with caution.
namespace mine_grid
{
    Cell::Cell(const sf::Vector2i &grid_position)
    {
        _grid_position = grid_position;
    }
    Cell::~Cell()
    {

    }
}