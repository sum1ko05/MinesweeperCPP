#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "core/include/object.hpp"
#include "tile_grid.hpp"
#include "tile.hpp"
#define ushort unsigned short

//Namespace for everything with grid. It's Minesweeper specific, so copy with caution.
namespace mine_grid
{
    class DigitDisplay : public TileGrid
    {
    private:
        ushort _display_value = 0;
    public:
        DigitDisplay(ushort digits);
        ~DigitDisplay();

        void setValue(ushort new_value);

        //void handleEvent(sf::Event event, sf::RenderWindow &window) override;
        //void update(float deltaTime) override;
        //void render(sf::RenderWindow &window) override;
    };
}