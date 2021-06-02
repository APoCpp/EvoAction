#include "entity_list.hpp"

EntityList::EntityList(initializer_list list) : _list(list) { }

EntityList::iterator_type EntityList::begin()
{
    return _list.begin();
}

EntityList::const_iterator_type EntityList::begin() const
{
    return _list.cbegin();
}

EntityList::iterator_type EntityList::end()
{
    return _list.end();
}

EntityList::const_iterator_type EntityList::end() const
{
    return _list.cend();
}

void EntityList::remove(const iterator_type &iterator)
{
    _list.erase(iterator);
}
