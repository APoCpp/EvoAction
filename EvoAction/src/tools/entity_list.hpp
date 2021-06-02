#ifndef EVO_ACTION_TOOLS_ENTITY_LIST_HPP
#define EVO_ACTION_TOOLS_ENTITY_LIST_HPP

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

    using value_type            = std::shared_ptr<Entity>;
    using list_type             = std::list<value_type>;

    using iterator_type         = typename list_type::iterator;
    using const_iterator_type   = typename list_type::const_iterator;

    using initializer_list      = std::initializer_list<value_type>;

public:

    EntityList() = default;
    EntityList(initializer_list list);

    virtual ~EntityList() = default;

    iterator_type begin();
    const_iterator_type begin() const;

    iterator_type end();
    const_iterator_type end() const;

    template<class _Derived>
    iterator_type insert(const _Derived &value)
    {
        return _list.push_back(value_type(new _Derived(value))), --_list.end();
    }

    void remove(const iterator_type &iterator);

protected:

    list_type _list;

};

#endif
