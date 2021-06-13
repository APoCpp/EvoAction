#ifndef EVO_ACTION_SYSTEM_DESTRUCTIBLE_HPP
#define EVO_ACTION_SYSTEM_DESTRUCTIBLE_HPP

# include "collidable.hpp"
# include <cstdint>

/*!
    \class Destructible
    \brief Class that implements the ability to be destructible
*/
class Destructible : public Collidable
{
public:

    using health_type = float;

    enum Type : std::uint8_t
    {
        Object,
        Actor
    };

public:

    Destructible(identifier_type id, Type type, coordinates_type position, rotation_type rotation, radius_type radius, health_type health);

    virtual ~Destructible() = default;

    /*!
        \brief Get type of the destructible
        \return Type
    */
    [[nodiscard]] Type type() const;

    /*!
        \brief Get alive state of the destructible
        \return bool
    */
    [[nodiscard]] bool alive() const;

    /*!
        \brief Get health of the destructible
        \return health_type
        \see set_health
    */
    [[nodiscard]] health_type health() const;

    /*!
        \brief Set health of the destructible
        \param new health
        \see health
    */
    void set_health(const health_type &health);

protected:

    Type _type;
    health_type _health;

};

#endif
