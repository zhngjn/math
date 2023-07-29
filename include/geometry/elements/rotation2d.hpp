#ifndef GEOMETRY_ELEMENTS_ROTATION2D_HPP_ 
#define GEOMETRY_ELEMENTS_ROTATION2D_HPP_

#include "util/utility.hpp"
#include "elements/vector2d.hpp"

namespace math
{
namespace geometry 
{

template <typename T>
struct Rotation2D 
{
    Rotation2D(T theta) : theta_(theta) 
    {
        theta_ = util::normalize(theta_, 0.0, 2 * util::constants::PI<T>);
    }
    Rotation2D() : Rotation2D(T{}) {}

    T theta_;
};

template <typename T>
bool operator==(const Rotation2D<T>& lhs, const Rotation2D<T>& rhs)
{
    return std::fabs(lhs.theta_ - rhs.theta_) < util::constants::epsilon<T>();
}

template <typename T>
bool operator!=(const Rotation2D<T>& lhs, const Rotation2D<T>& rhs)
{
    return !(lhs == rhs);
}

template <typename T>
std::ostream& operator<<(std::ostream& strm, const Rotation2D<T>& rotation)
{
    return strm << "Rotation(" << rotation.theta_ << ")";
}

using Rotation2d = Rotation2D<double>;
using Rotation2f = Rotation2D<float>;

using Rotation2 = Rotation2D<config::FloatingType>;

} // namespace geometry
} // namespace math

#endif // GEOMETRY_ELEMENTS_ROTATION2D_HPP_