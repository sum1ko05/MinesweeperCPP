#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "core/include/object.hpp"
#define ushort unsigned short
#define cell_size_f 32.f

//Namespace for everything with grid. It's Minesweeper specific, so copy with caution.
namespace mine_grid
{
    class Tile : public mine_core::SpriteObject
    {
    private:
        //Cell position is relative to grid
        sf::Vector2i _grid_position;
    public:
        //ushort neighbor_mines;
        sf::Vector2i tileTexturePosition;
    protected:
        virtual sf::IntRect getTextureCut(){return sf::IntRect(tileTexturePosition.x*cell_size_f,
                                                               tileTexturePosition.y*cell_size_f,
                                                               cell_size_f, cell_size_f);}
        //bool is_mouse_inside();
    public:
        Tile(const sf::Vector2i &grid_position);
        ~Tile();

        const sf::Vector2i& getGridPosition()
        {
            return _grid_position;
        }
        
        //void handleEvent(sf::Event event, sf::RenderWindow &window) override;
        void render(sf::RenderWindow &window) override;
    };
}