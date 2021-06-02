#ifndef EVO_ACTION_TOOLS_ENTITY_LIST_HPP
#define EVO_ACTION_TOOLS_ENTITY_LIST_HPP

# include <system/entity.hpp>

# include <list>
# include <memory>

/*!
    \class List
    \brief A class that implements a list container
*/
template <class _Type>
class List
{
public:

    using value_type    = _Type;
    using size_type     = std::size_t;

private:

    struct Node
    {
        template <class _Derived>
        explicit Node(const _Derived &derived, Node *next) : value(new _Derived(derived)), next(next) { }

        virtual ~Node()
        {
            delete value;
        }

        value_type *value;
        Node *next;
    };

public:

    class iterator
    {
    public:

        explicit iterator(Node *node) : _node(node) { }

        operator bool()
        {
            return static_cast<bool>(_node);
        }

        iterator &operator++()
        {
            return _node = _node->next, *this;
        }

        const iterator &operator++() const
        {
            return _node = _node->next, *this;
        }

        value_type *operator->()
        {
            return _node->value;
        }

        const value_type *operator->() const
        {
            return _node->value;
        }

        value_type *operator*()
        {
            return _node->value;
        }

        const value_type *operator*() const
        {
            return _node->value;
        }

    protected:

        mutable Node *_node;

    };

public:

    List() : _head(nullptr), _size(0) { }

    virtual ~List()
    {
        clear();
    }

    /*!
        \brief Getting an iterator to a head element
        \result iterator
    */
    [[nodiscard]] iterator head()
    {
        return iterator(_head);
    }

    /*!
        \brief Getting an const iterator to a head element
        \result const iterator
    */
    [[nodiscard]] const iterator head() const
    {
        return iterator(_head);
    }

    /*!
        \brief Insert new element into the list
        \param iterator
        \see erase
    */
    template <class _Derived>
    iterator insert(const _Derived &derived)
    {
        return _size++, iterator(_head = new Node(derived, _head));
    }

    /*!
        \brief Erase element from the list
        \param iterator
        \see insert
    */
    void erase(const iterator &iterator)
    {
        Node *curr = _head, *prev = nullptr;
        while (curr)
        {
            if (curr->value == *iterator)
            {
                if (prev) prev->next = curr->next;
                else _head = curr->next;
                delete curr;
                _size--;
                break;
            }
            prev = curr, curr = curr->next;
        }
    }

    /*!
        \brief Getting size of the list
        \result size_type
    */
    size_type size() const
    {
        return _size;
    }

    /*!
        \brief Getting an iterator to a head element
    */
    void clear()
    {
        while (_head)
        {
            Node *next = _head->next;
            delete _head;
            _head = next;
        }
        _size = 0;
    }

protected:

    Node *_head;
    size_type _size;

};

#endif
