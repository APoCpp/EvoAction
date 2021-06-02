#include <SFML/Graphics.hpp>

#include <iostream>
#include <system/actor.hpp>

int main(int argc, char *argv[])
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "EvoAction");

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        window.clear(sf::Color::Black);

        // => Draw

        window.display();
    }

    return 0;
}
