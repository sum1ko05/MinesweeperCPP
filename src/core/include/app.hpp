#pragma once
#include <SFML/Graphics.hpp>
#include "object.hpp"

//Namespace for all core features. It could be used for any application.
namespace mine_core
{
    class App
    {
    private:
        sf::RenderWindow window;
        std::vector<std::unique_ptr<mine_core::SpriteObject>> objects;

        unsigned int _screenWidth;
        unsigned int _screenHeight;
    public:
        App(unsigned int screenWidth=640, unsigned int screenHeight=480);
        ~App();
        void run();
    private:
        void ready();
        void handle_events();
        void update();
        void render();
    };
}