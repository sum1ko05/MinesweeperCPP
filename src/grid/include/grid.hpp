#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "core/include/object.hpp"
#include "cell.hpp"

//Namespace for everything with grid. It's Minesweeper specific, so copy with caution.
namespace mine_grid
{
    class Grid : public mine_core::SpriteObject
    {
    private:
        std::vector<std::vector<std::unique_ptr<mine_grid::Cell>>> _grid;
    public:
        Grid(unsigned short gridWidth, unsigned short gridHeight);
        ~Grid();

        void setTexture(const sf::Texture &texture, bool resetRect = false);

        void render(sf::RenderWindow &window) override;
    };
}