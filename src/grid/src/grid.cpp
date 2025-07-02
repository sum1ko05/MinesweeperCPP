#include "grid/include/grid.hpp"
#include <SFML/Graphics.hpp>
#include "core/include/object.hpp"
#include "grid/include/cell.hpp"
#define ushort unsigned short
#define cell_size 32.f
#include <iostream>

//Namespace for everything with grid. It's Minesweeper specific, so copy with caution.
namespace mine_grid
{
    Grid::Grid(ushort gridWidth, ushort gridHeight)
    {
        for(ushort i = 0; i < gridWidth; i++)
        {
            std::vector<std::unique_ptr<mine_grid::Cell>> column = {};
            for(ushort j = 0; j < gridHeight; j++)
            {
                sf::Vector2i new_pos(i, j);
                std::unique_ptr<Cell> new_cell = std::make_unique<Cell>(new_pos);
                column.push_back(std::move(new_cell));
            }
            _grid.push_back(std::move(column));
        }
    }
    Grid::~Grid()
    {

    }

    void Grid::setTexture(const sf::Texture &texture, bool resetRect)
    {
        _texture = texture;
        for(ushort i = 0; i < _grid.size(); i++)
        {
            for(ushort j = 0; j < _grid[i].size(); j++)
            {
                _grid[i][j] -> setTexture(_texture, resetRect);
            }
        }
    }

    void Grid::render(sf::RenderWindow &window)
    {
        sf::Vector2f pivot = getPosition();
        for(ushort i = 0; i < _grid.size(); i++)
        {
            for(ushort j = 0; j < _grid[i].size(); j++)
            {
                sf::Vector2f cell_pos = pivot + (static_cast<sf::Vector2f>(_grid[i][j] -> getGridPosition()) * cell_size);
                _grid[i][j] -> setPosition(cell_pos);
                _grid[i][j] -> render(window);
            }
        }
    }
}