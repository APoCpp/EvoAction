#ifndef EVO_ACTION_TOOLS_LIST_HPP
#define EVO_ACTION_TOOLS_LIST_HPP

# include <system/entity.hpp>

# include <list>
# include <memory>

/*!
    \class EntityList
    \brief Class that implements the list container for entities
*/
class EntityList
{
public:

    using value_type            = Entity;
    using value_pointer_type    = std::shared_ptr<value_type>;
    using list_type             = std::list<value_pointer_type>;

    using iterator_type         = typename list_type::iterator;
    using const_iterator_type   = typename list_type::const_iterator;

public:

    virtual ~EntityList() = default;

    iterator_type begin()
    {
        return _list.begin();
    }

    const_iterator_type begin() const
    {
        return _list.begin();
    }

    iterator_type end()
    {
        return _list.end();
    }

    const_iterator_type end() const
    {
        return _list.end();
    }

    template <class _Derived>
    iterator_type insert(const _Derived &value)
    {
        return _list.push_back(value_pointer_type(new _Derived(value))), --_list.end();
    }

    void remove(const iterator_type &iterator)
    {
        _list.erase(iterator);
    }

protected:

    list_type _list;

};

#endif
