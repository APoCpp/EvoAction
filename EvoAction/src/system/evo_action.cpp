#include "evo_action.hpp"

#include "actor.hpp"

EvoAction::EvoAction(unsigned int window_width, unsigned int window_height)
    : sf::RenderWindow(video_mode_type(window_width, window_height), window_name, sf::Style::Titlebar | sf::Style::Close), _entity_list()
{
    std::srand(std::time(nullptr));
    for (size_t i = 0; i < 10; ++i)
    {
        _entity_list.insert<Actor>({ i, Vector2<float> {
            static_cast<float>(1 + rand() % window_width),
            static_cast<float>(1 + rand() % window_height)
        }, 0.f, 100.f });
    }
}

int EvoAction::exec()
{
    while (isOpen())
    {
        sf::Event event;
        while (pollEvent(event))
            if (event.type == sf::Event::Closed) close();

        clear();

        for (EntityList::value_type &entity : _entity_list)
            draw(*std::dynamic_pointer_cast<Actor>(entity));

        display();
    }
    return 0;
}
