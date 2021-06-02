#ifndef EVO_ACTION_SYSTEM_ACTOR_HPP
#define EVO_ACTION_SYSTEM_ACTOR_HPP

# include "destructible.hpp"

# include <SFML/Graphics/RenderTarget.hpp>
# include <SFML/Graphics/CircleShape.hpp>

/*!
    \class Actor
    \brief Class that implements the actor
*/
class Actor : public Destructible, public sf::Drawable
{
public:

    /// \brief Circle radius equal [ health / size_ratio ]
    static constexpr float size_ratio           = 15.f;
    static constexpr std::size_t point_count    = 60;

public:

    Actor(identifier_type id, coordinates_type position, rotation_type rotation, health_type health);

    virtual ~Actor() = default;

private:

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

protected:

    mutable sf::CircleShape _shape;

};

#endif
