#pragma once
#include <SFML/Graphics.hpp>

namespace mine_core
{
    class App
    {
    private:
        sf::RenderWindow window;
        std::vector<std::unique_ptr<sf::Sprite>> objects;
    public:
        App();
        ~App();
        void run();
    private:
        void handle_events();
        void update();
        void render();
    };
}