#pragma once
#include <SFML/Graphics.hpp>
#include "core/include/object.hpp"
//#include "grid/include/grid.hpp"
#define IR_SM IntRect_StateMachine
#define ushort unsigned short

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
        bool _is_flagged;
        bool _game_ended;

    public:
        ushort neighbor_mines;
        SpriteObject* parent;

    private:
        sf::IntRect getTextureCut();
        bool is_mouse_inside();
    public:
        Cell(const sf::Vector2i &grid_position);
        ~Cell();

        sf::Vector2i getGridPosition()
        {
            return _grid_position;
        }

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

        void handleEvent(sf::Event event, sf::RenderWindow &window) override;
        void render(sf::RenderWindow &window) override;
    };
}