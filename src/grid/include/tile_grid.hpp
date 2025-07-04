#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "core/include/object.hpp"
#include "tile.hpp"
#define ushort unsigned short

//Namespace for everything with grid. It's Minesweeper specific, so copy with caution.
namespace mine_grid
{
    class TileGrid : public mine_core::SpriteObject
    {
    private:
        std::vector<std::vector<std::unique_ptr<mine_grid::Tile>>> _grid;
        ushort _grid_width;
        ushort _grid_height;

        //void reset_cells();
        //unsigned short get_neighbor_mines(ushort mine_x, ushort mine_y);
    public:
        TileGrid(ushort gridWidth, ushort gridHeight);
        ~TileGrid();

        const ushort getWidth(){return _grid_width;}
        const ushort getHeight(){return _grid_height;}

        void setTexture(const sf::Texture &texture, bool resetRect = false);
        //void call_parent_func(std::string func, sf::Vector2i auto_open_arg = sf::Vector2i(0,0)) override;


        //void game_setup(int mine_amount);
        //void end_game();
        //void auto_open(ushort cell_x, ushort cell_y);

        //void handleEvent(sf::Event event, sf::RenderWindow &window) override;
        void render(sf::RenderWindow &window) override;
    };
}