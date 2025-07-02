#pragma once
#include <SFML/Graphics.hpp>
#include "object.hpp"

namespace mine_core
{
    class App
    {
    private:
        sf::RenderWindow window;
        std::vector<std::unique_ptr<mine_core::SpriteObject>> objects;
    public:
        App();
        ~App();
        void run();
    private:
        void ready();
        void handle_events();
        void update();
        void render();
    };
}