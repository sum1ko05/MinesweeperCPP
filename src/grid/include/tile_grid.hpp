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

        sf::Vector2i setBorderState(ushort width, ushort height, ushort x, ushort y);
    public:
        TileGrid(ushort gridWidth, ushort gridHeight, const sf::Vector2i &tile_size=sf::Vector2i(32,32));
        ~TileGrid();

        const ushort getWidth(){return _grid_width;}
        const ushort getHeight(){return _grid_height;}
        Tile* getTile(ushort x, ushort y)
        {
            return _grid[x][y].get();
        }

        void setTexture(const sf::Texture &texture, bool resetRect = false);

        //void handleEvent(sf::Event event, sf::RenderWindow &window) override;
        void render(sf::RenderWindow &window) override;
    };
}