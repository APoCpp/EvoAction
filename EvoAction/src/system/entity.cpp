#include "entity.hpp"

Entity::Entity(identifier_type id) : _id(id) { }

Entity::identifier_type Entity::id() const
{
    return _id;
}
