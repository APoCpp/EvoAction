#ifndef EVO_ACTION_SYSTEM_COLLIDER_HPP
#define EVO_ACTION_SYSTEM_COLLIDER_HPP

# include "placeable.hpp"

/*!
    \class Collidable
    \brief Class that implements the ability to check collisions with objects
*/
class Collidable : public Placeable
{
public:

    using radius_type = float;

public:

    Collidable(identifier_type id, coordinates_type position, rotation_type rotation, radius_type radius);

    /*!
        \brief Get collision state with another collider
        \param collidable
        \return bool
    */
    [[nodiscard]] bool is_collided(const Collidable& collidable) const;


    /*!
        \brief Get radius of the collidable
        \return radius_type
        \see set_rotation
    */
    [[nodiscard]] radius_type radius() const;

    /*!
        \brief Set radius of the collidable
        \param new radius
        \see radius
    */
    void set_radius(const radius_type &radius);

protected:

    radius_type _radius;

};

#endif
