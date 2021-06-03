#ifndef EVO_ACTION_SYSTEM_HPP
#define EVO_ACTION_SYSTEM_HPP

# include <tools/entity_list.hpp>

# include <SFML/Graphics.hpp>

class EvoAction : sf::RenderWindow
{
public:

    static constexpr auto window_name = "EvoAction";

    using entity_list_type      = EntityList;
    using video_mode_type       = sf::VideoMode;

    EvoAction(unsigned int window_width, unsigned int window_height);

    int exec();

protected:

    entity_list_type _entity_list;

};

#endif
