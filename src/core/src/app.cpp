#include "core/include/app.hpp"
#include <SFML/Graphics.hpp>

namespace mine_core
{
    App::App(): window(sf::VideoMode(640, 480), "Minesweeper CPP")
    {

    }

    #pragma region run_functions

    void App::handle_events()
    {
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }

            // Passing event to all objects
            for (auto& obj : objects){
                //obj->handleEvent(event, window);
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
            window.draw(*obj);
        }

        window.display();
    }
    #pragma endregion
    
    void App::run()
    {
        while (window.isOpen()) {
            handle_events();
            update();
            render();
        }
    }
}