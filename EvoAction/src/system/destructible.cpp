#include "destructible.hpp"

Destructible::Destructible(identifier_type id, Type type, coordinates_type position, rotation_type rotation, radius_type radius, health_type health)
    : Collidable(id, position, rotation, radius), _type(type), _health(health) { }

Destructible::Type Destructible::type() const
{
    return _type;
}

bool Destructible::alive() const
{
    return _health > 0.f;
}

Destructible::health_type Destructible::health() const
{
    return _health;
}

void Destructible::set_health(const health_type &health)
{
    _health = health;
}
