#include "placeable.hpp"

Placeable::Placeable(identifier_type id, coordinates_type position, rotation_type rotation)
    : Entity(id), _position(position), _rotation(rotation) { }

Placeable::coordinates_type Placeable::position() const
{
    return _position;
}

void Placeable::set_position(const coordinates_type &position)
{
    _position = position;
}

Placeable::rotation_type Placeable::rotation() const
{
    return _rotation;
}

void Placeable::set_rotation(const rotation_type &rotation)
{
    _rotation = rotation;
}
