#include "grid/include/tile_grid.hpp"
#include <SFML/Graphics.hpp>
#include "core/include/object.hpp"
#include "grid/include/tile.hpp"
#define ushort unsigned short
#define cell_size_f 32.f
#include <iostream>

//Namespace for everything with grid. It's Minesweeper specific, so copy with caution.
namespace mine_grid
{
    TileGrid::TileGrid(ushort gridWidth, ushort gridHeight)
    {
        for(ushort i = 0; i < gridWidth; i++)
        {
            std::vector<std::unique_ptr<mine_grid::Tile>> column = {};
            for(ushort j = 0; j < gridHeight; j++)
            {
                sf::Vector2i new_pos(i, j);
                std::unique_ptr<Tile> new_tile = std::make_unique<Tile>(new_pos);
                new_tile -> parent = this;
                new_tile -> tileTexturePosition = setBorderState(gridWidth, gridHeight, i, j);
                column.push_back(std::move(new_tile));
            }
            _grid.push_back(std::move(column));
        }
        _grid_height = gridHeight;
        _grid_width = gridWidth;
    }
    TileGrid::~TileGrid()
    {

    }
    sf::Vector2i TileGrid::setBorderState(ushort width, ushort height, ushort x, ushort y)
    {
        bool left = x==0 ? true : false;
        bool right = x==width-1 ? true : false;
        bool up = y==0 ? true : false;
        bool down = y==height-1 ? true : false;

        if(left)
        {
            if(up) return sf::Vector2i(0, 0);
            else if(down) return sf::Vector2i(0, 2);
            else return sf::Vector2i(0, 1);
        }
        else if(right)
        {
            if(up) return sf::Vector2i(2, 0);
            else if(down) return sf::Vector2i(2, 2);
            else return sf::Vector2i(2, 1);
        }
        else
        {
            if(up) return sf::Vector2i(1, 0);
            else if(down) return sf::Vector2i(1, 2);
            else return sf::Vector2i(1, 1);
        }
    }
    
    void TileGrid::setTexture(const sf::Texture &texture, bool resetRect)
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
    
    void TileGrid::render(sf::RenderWindow &window)
    {
        sf::Vector2f pivot = getPosition();
        for(ushort i = 0; i < _grid.size(); i++)
        {
            for(ushort j = 0; j < _grid[i].size(); j++)
            {
                sf::Vector2f cell_pos = pivot + (static_cast<sf::Vector2f>(_grid[i][j] -> getGridPosition()) * cell_size_f);
                _grid[i][j] -> setPosition(cell_pos);
                _grid[i][j] -> render(window);
            }
        }
    }
}