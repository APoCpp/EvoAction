#include "entity_list.hpp"

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
    on_remove(iterator), _list.erase(iterator);
}
