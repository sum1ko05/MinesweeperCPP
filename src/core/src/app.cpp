#include "core/include/app.hpp"
#include <SFML/Graphics.hpp>
#include "core/include/object.hpp"
#include "grid/include/grid.hpp"
#include <iostream>

//Namespace for all core features. It could be used for any application.
namespace mine_core
{
    App::App(): window(sf::VideoMode(640, 480), "Minesweeper CPP")
    {
        
    }

    App::~App()
    {

    }

    #pragma region run_functions

    void App::ready()
    {
        sf::Vector2f pos(50, 50);
        sf::Texture texture;
        texture.loadFromFile("../assets/trollface.png");
        std::unique_ptr<SpriteObject> trollface = std::make_unique<SpriteObject>();
        trollface -> setTexture(texture);
        trollface -> setPosition(pos);
        objects.push_back(std::move(trollface));

        sf::Texture cell_texture;
        cell_texture.loadFromFile("../assets/cell_test.png");
        std::unique_ptr<mine_grid::Grid> grid = std::make_unique<mine_grid::Grid>(10,10);
        grid -> setTexture(cell_texture);
        grid -> setPosition(pos);
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

    }

    void App::render()
    {
        window.clear();
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