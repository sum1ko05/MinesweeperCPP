#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "core/include/object.hpp"
#include "grid/include/tile.hpp"
#define ushort unsigned short
#define cell_size_f 32.f

namespace mine_other
{
    enum class EmojiState
    {
        Normal = 5,
        Worried = 6,
        Sob = 7,
        Winner = 8
    };

    class Emoji: public mine_grid::Tile
    {
    private:
        //Cell position is relative to grid
        //sf::Vector2i _grid_position;
    public:
        EmojiState emotion;
        bool game_lost;
        bool game_won;
        //ushort neighbor_mines;
        //sf::Vector2i tileTexturePosition;
    protected:
        sf::IntRect getTextureCut() override
        {
            //std::cout << static_cast<int>(emotion) << std::endl;
            return sf::IntRect(static_cast<int>(emotion)*cell_size_f,
                               cell_size_f, cell_size_f, cell_size_f);
        }
        //bool is_mouse_inside();
    public:
        Emoji(const sf::Vector2i &grid_position = sf::Vector2i(0,0)):Tile(grid_position)
        {
            emotion = EmojiState::Normal;
        }
        //~Emoji();
        //void handleEvent(sf::Event event, sf::RenderWindow &window) override;
        /*
        void render(sf::RenderWindow &window) override
        {
            setTextureRect(getTextureCut());
            if(getTexture() == nullptr) std::cout << "Texture Failure detected!\n";
            window.draw(*this);
        };
        */
    };
}