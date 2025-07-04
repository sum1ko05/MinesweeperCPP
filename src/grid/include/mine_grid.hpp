#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "core/include/object.hpp"
#include "cell.hpp"
#define ushort unsigned short

//Namespace for everything with grid. It's Minesweeper specific, so copy with caution.
namespace mine_grid
{
    class MineGrid : public mine_core::SpriteObject
    {
    private:
        std::vector<std::vector<std::unique_ptr<mine_grid::Cell>>> _grid;
        unsigned short _grid_width;
        unsigned short _grid_height;

        void reset_cells();
        unsigned short get_neighbor_mines(ushort mine_x, ushort mine_y);
    public:
        MineGrid(unsigned short gridWidth, unsigned short gridHeight);
        ~MineGrid();

        void setTexture(const sf::Texture &texture, bool resetRect = false);
        void call_parent_func(std::string func, sf::Vector2i auto_open_arg = sf::Vector2i(0,0)) override;

        void game_setup(int mine_amount);
        void end_game();
        void auto_open(ushort cell_x, ushort cell_y);

        void handleEvent(sf::Event event, sf::RenderWindow &window) override;
        void render(sf::RenderWindow &window) override;
    };
}