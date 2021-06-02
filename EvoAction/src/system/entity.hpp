#ifndef EVO_ACTION_SYSTEM_ENTITY_HPP
#define EVO_ACTION_SYSTEM_ENTITY_HPP

# include <cstdint>

class EntityList;

/*!
    \class Entity
    \brief A class that implements the generic entity identifier store
*/
class Entity
{
public:

    using identifier_type = std::size_t;

    friend class EntityList;

public:

    Entity(identifier_type id);

    virtual ~Entity() = default;

    /*!
        \brief Get identifier of the entity
        \return identifier
    */
    [[nodiscard]] identifier_type id() const;

protected:

    identifier_type _id;

};

#endif
