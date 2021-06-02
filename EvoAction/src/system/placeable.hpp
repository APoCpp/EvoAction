#ifndef EVO_ACTION_SYSTEM_PLACEABLE_HPP
#define EVO_ACTION_SYSTEM_PLACEABLE_HPP

# include "entity.hpp"

# include <tools/math.hpp>

/*!
    \class Placeable
    \brief Class that implements the ability to be placed in space
*/
class Placeable : public Entity
{
public:

    using coordinates_type  = Vector2<float>;
    using rotation_type     = float;

public:

    Placeable(identifier_type id, coordinates_type position, rotation_type rotation);

    virtual ~Placeable() = default;

    /*!
        \brief Get position of the placeable
        \return coordinates_type
        \see set_position
    */
    [[nodiscard]] coordinates_type position() const;

    /*!
        \brief Set position of the placeable
        \param new position
        \see position
    */
    void set_position(const coordinates_type &position);

    /*!
        \brief Get rotation of the placeable
        \return rotation_type
        \see set_rotation
    */
    [[nodiscard]] rotation_type rotation() const;

    /*!
        \brief Set rotation of the placeable
        \param new rotation
        \see rotation
    */
    void set_rotation(const rotation_type &rotation);

protected:

    coordinates_type _position;
    rotation_type _rotation;

};

#endif
