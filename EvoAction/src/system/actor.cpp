#include "actor.hpp"

Actor::Actor(identifier_type id, coordinates_type position, rotation_type rotation, health_type health)
    : Destructible(id, Destructible::Actor, position, rotation, health / size_ratio, health), _shape(_radius, point_count) { }

void Actor::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    _shape.setPosition(_position);
    _shape.setRotation(_rotation);
    _shape.setRadius(_radius);
    target.draw(_shape);
}
