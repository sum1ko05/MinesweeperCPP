#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "core/include/object.hpp"
#define ushort unsigned short

//Namespace for everything with grid. It's Minesweeper specific, so copy with caution.
namespace mine_grid
{
    class Tile : public mine_core::SpriteObject
    {
    private:
        //Cell position is relative to grid
        sf::Vector2i _grid_position;

        //bool _is_opened;
        //bool _has_mine;
        //bool _is_flagged;
        //bool _game_ended;

    public:
        //ushort neighbor_mines;

    protected:
        virtual sf::IntRect getTextureCut(){return sf::IntRect(0,0,0,0);}
        //bool is_mouse_inside();
    public:
        Tile(const sf::Vector2i &grid_position);
        ~Tile();

        const sf::Vector2i& getGridPosition()
        {
            return _grid_position;
        }

        /*
        void reset_cell()
        {
            _is_opened = false;
            _has_mine = false;
            _is_flagged = false;
            _game_ended = false;
        }
        bool get_mine();
        void set_mine(bool has_mine);
        void end_game();
        void open_cell();
        void flag_cell();
        */

        //void handleEvent(sf::Event event, sf::RenderWindow &window) override;
        void render(sf::RenderWindow &window) override;
    };
}