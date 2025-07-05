#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "core/include/object.hpp"
#include "cell.hpp"
#include "other/include/button.hpp"
#include "other/include/emoji.hpp"
#include "digit_display.hpp"
#define ushort unsigned short

//Namespace for everything with grid. It's Minesweeper specific, so copy with caution.
namespace mine_grid
{
    class MineGrid : public mine_core::SpriteObject
    {
    private:
        std::vector<std::vector<std::unique_ptr<mine_grid::Cell>>> _grid;
        ushort _grid_width;
        ushort _grid_height;
        int _mine_amount;
        bool _game_started;

        void game_start(ushort init_x, ushort init_y);
        void reset_cells();
        ushort get_neighbor_mines(ushort mine_x, ushort mine_y);
        ushort MineGrid::get_neighbor_flags(ushort cell_x, ushort cell_y);
        int cells_remaining;

        bool mouse_button_hovering = false;

        float time_passed = 0;
    public:
        MineGrid(ushort gridWidth, ushort gridHeight, int mine_amount);
        ~MineGrid();

        mine_other::Emoji* emoji;
        DigitDisplay* time_display;
        DigitDisplay* free_cells_display;
        bool game_lost;
        bool game_won;

        void setTexture(const sf::Texture &texture, bool resetRect = false);
        void call_parent_func(std::string func, sf::Vector2i auto_open_arg = sf::Vector2i(0,0)) override;
        void set_mouse_holding(bool value){mouse_button_hovering = value;}

        void game_setup(int mine_amount);
        void end_game(int end_code);
        void zero_auto_open(ushort cell_x, ushort cell_y);
        void flag_auto_open(ushort cell_x, ushort cell_y);

        void on_cell_opened();

        void handleEvent(sf::Event event, sf::RenderWindow &window) override;
        void update(float deltaTime) override
        {
            if(_game_started && !(game_lost || game_won)) time_passed += deltaTime;

            if(game_lost) emoji -> emotion = mine_other::EmojiState::Sob;
            else if(game_won) emoji -> emotion = mine_other::EmojiState::Winner;
            else if(mouse_button_hovering) emoji -> emotion = mine_other::EmojiState::Worried;
            else emoji -> emotion = mine_other::EmojiState::Normal;

            time_display -> setValue(time_passed);
            //std::cout << time_passed << " " << deltaTime << std::endl;
        }
        void render(sf::RenderWindow &window) override;
    };
}