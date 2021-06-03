#ifndef EVO_ACTION_TOOLS_MATH_HPP
#define EVO_ACTION_TOOLS_MATH_HPP

# include <SFML/System/Vector2.hpp>

# include <cmath>

template <class _Type>
using Vector2 = sf::Vector2<_Type>;

template <class _Type>
_Type calculate_distance(const Vector2<_Type> &p1, const Vector2<_Type> &p2)
{
    return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
}

#endif
