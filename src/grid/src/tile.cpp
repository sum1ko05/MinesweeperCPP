#include "grid/include/tile.hpp"
#include <SFML/Graphics.hpp>
#include "core/include/object.hpp"
#define ushort unsigned short
#define cell_size 32

//Namespace for everything with grid. It's Minesweeper specific, so copy with caution.
namespace mine_grid
{
    Tile::Tile(const sf::Vector2i &grid_position, const sf::Vector2i &tile_size)
    {
        _grid_position = grid_position;
        tileSize = tile_size;
    }
    Tile::~Tile()
    {

    }

    void Tile::render(sf::RenderWindow &window)
    {
        setTextureRect(getTextureCut());
        window.draw(*this);
    }
}