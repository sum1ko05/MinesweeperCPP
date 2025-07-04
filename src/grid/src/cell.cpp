#include "grid/include/cell.hpp"
#include <SFML/Graphics.hpp>
#include "core/include/object.hpp"
#include "grid/include/tile.hpp"
#define ushort unsigned short
#define cell_size 32

//Namespace for everything with grid. It's Minesweeper specific, so copy with caution.
namespace mine_grid
{
    
    Cell::Cell(const sf::Vector2i &grid_position):Tile(grid_position)
    {
        //_grid_position = grid_position;
    }
     //:Tile(grid_position)
    
    Cell::~Cell()
    {

    }
    
    sf::IntRect Cell::getTextureCut()
    {
        if(_is_opened && !_has_mine)
        {
            int left_corner = neighbor_mines * cell_size;
            return sf::IntRect(left_corner, 0, cell_size, cell_size);
        }
        else
        {
            if(_has_mine && _game_ended)
            {
                if(_is_opened)
                {
                    return sf::IntRect(cell_size * 2, cell_size, cell_size, cell_size);
                }
                else return sf::IntRect(cell_size * 1, cell_size, cell_size, cell_size);
            }
            else if(_is_flagged)
            {
                if(_game_ended && !_has_mine)
                {
                    return sf::IntRect(cell_size * 4, cell_size, cell_size, cell_size);
                }
                else return sf::IntRect(cell_size * 3, cell_size, cell_size, cell_size);
            }
            else if(_is_holding) return sf::IntRect(0, 0, cell_size, cell_size);
            else //Default
            {
                return sf::IntRect(0, cell_size, cell_size, cell_size);
            }
        }
    }

    const bool Cell::get_mine()
    {
        return _has_mine;
    }
    const bool Cell::get_flag()
    {
        return _is_flagged;
    }
    void Cell::set_mine(bool has_mine)
    {
        _has_mine = has_mine;
    }
    void Cell::end_game()
    {
        _game_ended = true;
    }

    void Cell::open_cell()
    {
        if(!_is_opened)
        {
            if(!game_started)
            {
                parent -> call_parent_func("game_start", getGridPosition());
            }
            if(!_is_flagged) 
            {
                _is_opened = true;
                if(_has_mine)
                {
                    parent -> call_parent_func("end_game", sf::Vector2i(0,0));
                }
                else
                {
                    parent -> call_parent_func("on_cell_opened");
                    if(neighbor_mines == 0) parent -> call_parent_func("zero_auto_open", getGridPosition());
                }
            }
        }
    }
    void Cell::manual_open_cell()
    {
        if(_is_opened && neighbor_mines != 0) parent -> call_parent_func("flag_auto_open", getGridPosition());
        open_cell();
    }
    void Cell::flag_cell()
    {
        if(game_started) _is_flagged = !_is_flagged;
    }

    void Cell::handleEvent(sf::Event event, sf::RenderWindow &window)
    {
        sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
        if(getGlobalBounds().contains(mouse_pos.x, mouse_pos.y))
        {
            if(event.type == sf::Event::MouseButtonReleased)
            {
                _is_holding = false;
                parent -> call_parent_func("set_mouse_holding", sf::Vector2i(0,0));
                if(event.mouseButton.button == sf::Mouse::Left && !_game_ended)
                {
                    manual_open_cell();
                }
            }
            if(event.type == sf::Event::MouseButtonPressed)
            {
                _is_holding = true;
                parent -> call_parent_func("set_mouse_holding", sf::Vector2i(1,1));
                if(event.mouseButton.button == sf::Mouse::Right && !_game_ended)
                {
                    flag_cell();
                }
            }
        }
        else _is_holding = false;
    }
    /*
    void Cell::render(sf::RenderWindow &window)
    {
        setTextureRect(getTextureCut());
        window.draw(*this);
    }
    */
}