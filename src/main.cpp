#include <SFML/Graphics.hpp>

//Ignore this code if you see it. It was only needed for test
int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "Hello World");
    sf::CircleShape shape(200);

    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        window.clear();
        window.draw(shape);
        window.display();
    }
    return 0;
}