#include "core/include/app.hpp"
#include <SFML/Graphics.hpp>
#include "core/include/object.hpp"
#include "grid/include/tile_grid.hpp"
#include "grid/include/mine_grid.hpp"
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
        std::unique_ptr<mine_grid::MineGrid> grid = std::make_unique<mine_grid::MineGrid>(grid_size.x,grid_size.y);
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

        button -> parent = grid.get();
        grid -> emoji = emoji.get();

        border -> setPosition(borderPos);
        grid -> setPosition(gridPos);
        grid -> game_setup(25);
        objects.push_back(std::move(button));
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

    void App::update()
    {
        for (auto& obj : objects){
            //No clock needed yet
            obj->update(0.f);
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
        ready();
        while (window.isOpen()) {
            handle_events();
            update();
            render();
        }
    }
}