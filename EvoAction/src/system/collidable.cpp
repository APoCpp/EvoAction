#include "collidable.hpp"

Collidable::Collidable(identifier_type id, coordinates_type position, rotation_type rotation, radius_type radius)
    : Placeable(id, position, rotation), _radius(radius) { }

bool Collidable::is_collided(const Collidable &collidable) const
{
    return calculate_distance(collidable.position(), _position) < _radius + collidable.radius();
}

Collidable::radius_type Collidable::radius() const
{
    return _radius;
}

void Collidable::set_radius(const radius_type &radius)
{
    _radius = radius;
}
