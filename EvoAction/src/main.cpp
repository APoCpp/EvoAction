#include <SFML/Graphics.hpp>

#include <system/actor.hpp>
#include <tools/entity_list.hpp>

const size_t window_width = 800, window_height = 600;

inline EntityList entity_list;

int main(int argc, char *argv[])
{
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "EvoAction", sf::Style::Titlebar | sf::Style::Close);

    std::srand(std::time(nullptr));
    for (size_t i = 0; i < 10; ++i)
    {
        entity_list.insert<Actor>({ i, Vector2<float> {
            static_cast<float>(1 + rand() % window_width),
            static_cast<float>(1 + rand() % window_height)
        }, 0.f, 100.f });
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        window.clear();

        for (EntityList::value_type &entity : entity_list)
            window.draw(*std::dynamic_pointer_cast<Actor>(entity).get());

        window.display();
    }
    return 0;
}
