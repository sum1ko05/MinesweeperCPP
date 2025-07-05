#include "core/include/app.hpp"
#include <SFML/Graphics.hpp>
#include "core/include/object.hpp"
#include "grid/include/tile_grid.hpp"
#include "grid/include/mine_grid.hpp"
#include "grid/include/digit_display.hpp"
#include "other/include/button.hpp"
#include "other/include/emoji.hpp"
#include <iostream>
#define cell_size 32

//Namespace for all core features. It could be used for any application.
namespace mine_core
{
    App::App(unsigned int screenWidth, unsigned int screenHeight): window(sf::VideoMode(640, 480), "Minesweeper CPP")
    {
        _screenWidth = screenWidth;
        _screenHeight = screenHeight;
        //Trying to optimise the app
        window.setFramerateLimit(15);
    }

    App::~App()
    {

    }

    #pragma region run_functions

    void App::ready()
    {
        float reset_section_height = 80.f;
        sf::Texture button_pressed_texture;
        sf::Texture button_texture;
        button_pressed_texture.loadFromFile("../assets/reset_button_pressed.png");
        button_texture.loadFromFile("../assets/reset_button.png");
        sf::Vector2f button_size(20.f, 20.f);
        std::unique_ptr<mine_other::SpriteButton> button = std::make_unique<mine_other::SpriteButton>();
        button -> setTexture(button_texture);
        button -> setReleasedTexture(button_texture);
        button -> setPressedTexture(button_pressed_texture);
        sf::Vector2f resetSectionCenter(_screenWidth / 2, reset_section_height / 2);
        sf::Vector2f button_pos = resetSectionCenter - button_size;
        button -> setPosition(button_pos);

        sf::Vector2i grid_size(15,10);

        sf::Texture border_texture;
        border_texture.loadFromFile("../assets/decorative_border.png");
        std::unique_ptr<mine_grid::TileGrid> border = std::make_unique<mine_grid::TileGrid>(grid_size.x+2,grid_size.y+2);
        border -> setTexture(border_texture);

        sf::Texture cell_texture;
        cell_texture.loadFromFile("../assets/tiles.png");
        std::unique_ptr<mine_grid::MineGrid> grid = std::make_unique<mine_grid::MineGrid>(grid_size.x,grid_size.y,35);
        grid -> setTexture(cell_texture);
        //Centering the grid
        sf::Vector2f mainSectionCenter(_screenWidth / 2, 
                                      ((_screenHeight - reset_section_height) / 2) + reset_section_height);
        sf::Vector2f gridCenter((cell_size*grid_size.x)/2, (cell_size*grid_size.y)/2);
        sf::Vector2f borderCenter((cell_size*(grid_size.x+2))/2, (cell_size*(grid_size.y+2))/2);
        sf::Vector2f gridPos = mainSectionCenter - gridCenter;
        sf::Vector2f borderPos = mainSectionCenter - borderCenter;

        sf::Texture emoji_texture;
        emoji_texture.loadFromFile("../assets/tiles.png");
        std::unique_ptr<mine_other::Emoji> emoji = std::make_unique<mine_other::Emoji>();
        sf::Vector2f emoji_pos = button_pos + sf::Vector2f(4.f, 4.f);
        emoji -> setTexture(emoji_texture);
        emoji -> setPosition(emoji_pos);

        sf::Texture digits_texture;
        digits_texture.loadFromFile("../assets/digits.png");
        std::unique_ptr<mine_grid::DigitDisplay> time_display = std::make_unique<mine_grid::DigitDisplay>(3);
        std::unique_ptr<mine_grid::DigitDisplay> free_cells_display = std::make_unique<mine_grid::DigitDisplay>(3);
        time_display -> setTexture(digits_texture);
        free_cells_display -> setTexture(digits_texture);
        time_display -> setPosition(sf::Vector2f(emoji_pos.x + 64, emoji_pos.y));
        free_cells_display -> setPosition(sf::Vector2f(emoji_pos.x - 64 - 32, emoji_pos.y));
        //time_display -> setValue(25);

        button -> parent = grid.get();
        grid -> emoji = emoji.get();
        grid -> time_display = time_display.get();
        grid -> free_cells_display = free_cells_display.get();

        border -> setPosition(borderPos);
        grid -> setPosition(gridPos);
        grid -> game_setup(25);

        objects.push_back(std::move(button));
        objects.push_back(std::move(time_display));
        objects.push_back(std::move(free_cells_display));
        objects.push_back(std::move(emoji));
        objects.push_back(std::move(border));
        objects.push_back(std::move(grid));
    }

    void App::handle_events()
    {
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }

            // Passing event to all objects
            for (auto& obj : objects){
                obj->handleEvent(event, window);
            }
        }
    }

    void App::update(float deltatime)
    {
        for (auto& obj : objects){
            //No clock needed yet
            obj->update(deltatime);
        }
    }

    void App::render()
    {
        window.clear(sf::Color(179, 179, 179, 255));
        // Drawing all objects
        for (const auto& obj : objects) {
            //window.draw(*obj);
            obj -> render(window);
        }

        window.display();
    }
    #pragma endregion
    
    void App::run()
    {
        sf::Clock clock;
        float deltatime = 0;
        ready();
        while (window.isOpen()) {
            deltatime = clock.restart().asSeconds();
            //clock.restart();

            handle_events();
            update(deltatime);
            render();
        }
    }
}