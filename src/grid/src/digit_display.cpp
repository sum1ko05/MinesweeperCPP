#include "grid/include/digit_display.hpp"
#include <SFML/Graphics.hpp>
#include "core/include/object.hpp"
#include "grid/include/tile.hpp"
#define ushort unsigned short
#define cell_size_f 32.f
#include <iostream>

//Namespace for everything with grid. It's Minesweeper specific, so copy with caution.
namespace mine_grid
{
    DigitDisplay::DigitDisplay(ushort digits):TileGrid(digits, 1, sf::Vector2i(21,32))
    {
        
    }
    DigitDisplay::~DigitDisplay()
    {

    }

    ushort pow10(ushort digits)
    {
        ushort result = 1;
        if(digits > 5) digits = 5;
        for(ushort i = 0; i < digits; i++)
        {
            result *= 10;
        }
        return result;
    }

    void DigitDisplay::setValue(ushort new_value)
    {
        _display_value = new_value;
        _display_value %= pow10(getWidth());
        //std::cout << _display_value << std::endl;
        ushort tmp = new_value;
        //I set less than getWidth() here because of underflow
        for(ushort i = getWidth()-1; i < getWidth(); i--)
        {
            //std::cout << i << std::endl;
            if(tmp <= 0 && i != getWidth()-1)
            {
                getTile(i,0) -> tileTexturePosition.x = 10;
                continue;
            }
            getTile(i,0) -> tileTexturePosition.x = tmp%10;
            tmp /= 10;
        }
    }
}