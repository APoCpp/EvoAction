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

public:

    virtual ~EntityList() = default;

    /*!
        \brief Get the initial iterator of the EntityList
        \return iterator_type
    */
    [[nodiscard]] iterator_type begin();

    /*!
        \brief Get the initial const iterator of the EntityList
        \return const_iterator_type
    */
    [[nodiscard]] const_iterator_type begin() const;

    /*!
        \brief Get the final iterator of the EntityList
        \return iterator_type
    */
    [[nodiscard]] iterator_type end();

    /*!
        \brief Get the final iterator of the EntityList
        \return const_iterator_type
    */
    [[nodiscard]] const_iterator_type end() const;

    /*!
        \brief Insert new value in the EntityList
        \return iterator_type
    */
    template<class _Derived>
    iterator_type insert(const _Derived &value)
    {
        _list.push_back(value_type(new _Derived(value)));
        auto it = --_list.end();
        on_insert(it);
        return it;
    }

    /*!
        \brief Remove value from the EntityList
    */
    void remove(const iterator_type &iterator);

public:

    /*!
        \brief Event notifying the about insert call of a new object
    */
    virtual void on_insert(const iterator_type &iterator) { }

    /*!
        \brief Event notifying the about remove call of a new object
    */
    virtual void on_remove(const iterator_type &iterator) { }

protected:

    list_type _list;

};

#endif
