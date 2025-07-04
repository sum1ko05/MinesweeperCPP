#include "grid/include/tile.hpp"
#include <SFML/Graphics.hpp>
#include "core/include/object.hpp"
#define ushort unsigned short
#define cell_size 32

//Namespace for everything with grid. It's Minesweeper specific, so copy with caution.
namespace mine_grid
{
    Tile::Tile(const sf::Vector2i &grid_position)
    {
        _grid_position = grid_position;
    }
    Tile::~Tile()
    {

    }

    /*
    sf::IntRect Tile::getTextureCut()
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
            else //Default
            {
                return sf::IntRect(0, cell_size, cell_size, cell_size);
            }
        }
    }

    bool Tile::get_mine()
    {
        return _has_mine;
    }
    void Tile::set_mine(bool has_mine)
    {
        _has_mine = has_mine;
    }
    void Tile::end_game()
    {
        _game_ended = true;
    }

    void Tile::open_cell()
    {
        if(!_is_opened)
        {
            if(!_is_flagged) 
            {
                _is_opened = true;
                if(_has_mine) parent -> call_parent_func("end_game");
                else if(neighbor_mines == 0) parent -> call_parent_func("auto_open", _grid_position);
            }
        }
    }
    void Tile::flag_cell()
    {
        _is_flagged = !_is_flagged;
    }
    */

    /*
    void Tile::handleEvent(sf::Event event, sf::RenderWindow &window)
    {
        
        sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
        if(getGlobalBounds().contains(mouse_pos.x, mouse_pos.y))
        {
            if(event.type == sf::Event::MouseButtonReleased)
            {
                if(event.mouseButton.button == sf::Mouse::Left && !_game_ended)
                {
                    open_cell();
                }
            }
            if(event.type == sf::Event::MouseButtonPressed)
            {
                if(event.mouseButton.button == sf::Mouse::Right && !_game_ended)
                {
                    flag_cell();
                }
            }
        }
        
    }
    */
    void Tile::render(sf::RenderWindow &window)
    {
        setTextureRect(getTextureCut());
        window.draw(*this);
    }
}