#include "grid/include/mine_grid.hpp"
#include <SFML/Graphics.hpp>
#include "core/include/object.hpp"
#include "grid/include/tile_grid.hpp"
#include "grid/include/cell.hpp"
#define ushort unsigned short
#define cell_size 32.f
#include <iostream>

//Namespace for everything with grid. It's Minesweeper specific, so copy with caution.
namespace mine_grid
{
    MineGrid::MineGrid(ushort gridWidth, ushort gridHeight)
    {
        for(ushort i = 0; i < gridWidth; i++)
        {
            std::vector<std::unique_ptr<mine_grid::Cell>> column = {};
            for(ushort j = 0; j < gridHeight; j++)
            {
                sf::Vector2i new_pos(i, j);
                std::unique_ptr<Cell> new_cell = std::make_unique<Cell>(new_pos);
                new_cell -> parent = this;
                column.push_back(std::move(new_cell));
            }
            _grid.push_back(std::move(column));
        }
        _grid_height = gridHeight;
        _grid_width = gridWidth;
    }
    MineGrid::~MineGrid()
    {

    }

    void MineGrid::reset_cells()
    {
        for(ushort i = 0; i < _grid.size(); i++)
        {
            for(ushort j = 0; j < _grid[i].size(); j++)
            {
                _grid[i][j] -> reset_cell();
            }
        }
    }

    void MineGrid::setTexture(const sf::Texture &texture, bool resetRect)
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
    void MineGrid::call_parent_func(std::string func, sf::Vector2i auto_open_arg)
    {
        if(func == "end_game") end_game();
        if(func == "auto_open") auto_open(auto_open_arg.x, auto_open_arg.y);
    }

    ushort MineGrid::get_neighbor_mines(ushort mine_x, ushort mine_y)
    {
        ushort result = 0;
        if(mine_x > 0 && mine_y > 0)
        {
            if(_grid[mine_x-1][mine_y-1] -> get_mine()) result++;
        }
        if(mine_y > 0)
        {
            if(_grid[mine_x][mine_y-1] -> get_mine()) result++;
        }
        if(mine_x < _grid_width-1 && mine_y > 0)
        {
            if(_grid[mine_x+1][mine_y-1] -> get_mine()) result++;
        }
        if(mine_x > 0)
        {
            if(_grid[mine_x-1][mine_y] -> get_mine()) result++;
        }
        if(mine_x < _grid_width-1)
        {
            if(_grid[mine_x+1][mine_y] -> get_mine()) result++;
        }
        if(mine_x > 0 && mine_y < _grid_height-1)
        {
            if(_grid[mine_x-1][mine_y+1] -> get_mine()) result++;
        }
        if(mine_y < _grid_height-1)
        {
            if(_grid[mine_x][mine_y+1] -> get_mine()) result++;
        }
        if(mine_x < _grid_width-1 && mine_y < _grid_height-1)
        {
            if(_grid[mine_x+1][mine_y+1] -> get_mine()) result++;
        }
        return result;
    }

    void MineGrid::game_setup(int mine_amount)
    {
        srand(time(0));
        reset_cells();
        for(int i = 0; i < mine_amount; i++)
        {
            while(true)
            {
                //Generate mine
                ushort mine_x = rand() % _grid_width;
                ushort mine_y = rand() % _grid_height;

                if(_grid[mine_x][mine_y] -> get_mine()) continue;
                else
                {
                    _grid[mine_x][mine_y] -> set_mine(true);
                    break;
                }
            }
        }
        for(ushort i = 0; i < _grid.size(); i++)
        {
            for(ushort j = 0; j < _grid[i].size(); j++)
            {
                _grid[i][j] -> neighbor_mines = get_neighbor_mines(i,j);
            }
        }
    }
    void MineGrid::end_game()
    {
        for(ushort i = 0; i < _grid.size(); i++)
        {
            for(ushort j = 0; j < _grid[i].size(); j++)
            {
                _grid[i][j] -> end_game();
            }
        }
    }
    void MineGrid::auto_open(ushort cell_x, ushort cell_y)
    {
        if(cell_x > 0 && cell_y > 0)
        {
            _grid[cell_x-1][cell_y-1] -> open_cell();
        }
        if(cell_y > 0)
        {
            _grid[cell_x][cell_y-1] -> open_cell();
        }
        if(cell_x < _grid_width-1 && cell_y > 0)
        {
            _grid[cell_x+1][cell_y-1] -> open_cell();
        }
        if(cell_x > 0)
        {
            _grid[cell_x-1][cell_y] -> open_cell();
        }
        if(cell_x < _grid_width-1)
        {
            _grid[cell_x+1][cell_y] -> open_cell();
        }
        if(cell_x > 0 && cell_y < _grid_height-1)
        {
            _grid[cell_x-1][cell_y+1] -> open_cell();
        }
        if(cell_y < _grid_height-1)
        {
            _grid[cell_x][cell_y+1] -> open_cell();
        }
        if(cell_x < _grid_width-1 && cell_y < _grid_height-1)
        {
            _grid[cell_x+1][cell_y+1] -> open_cell();
        }
    }

    void MineGrid::handleEvent(sf::Event event, sf::RenderWindow &window)
    {
        if(event.type == sf::Event::MouseButtonReleased || event.type == sf::Event::MouseButtonPressed)
        {
            for(ushort i = 0; i < _grid.size(); i++)
            {
                for(ushort j = 0; j < _grid[i].size(); j++)
                {
                    _grid[i][j] -> handleEvent(event, window);
                }
            }
        }
    }

    void MineGrid::render(sf::RenderWindow &window)
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