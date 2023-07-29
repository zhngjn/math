#ifndef GEOMETRY_ELEMENTS_POINT2D_HPP_ 
#define GEOMETRY_ELEMENTS_POINT2D_HPP_

#include <string>
#include <ostream>
#include <cmath>

#include "util/config.hpp"
#include "util/constants.hpp"
#include "util/conversion.hpp"

namespace math
{
namespace geometry 
{

template <typename T>
struct Point2D 
{
    Point2D(T x, T y) : x_(x), y_(y) {}
    Point2D() : Point2D(T{}, T{}) {}

    T norm() const
    {
        return std::sqrt(x_ * x_ + y_ * y_);
    }

    /**
     * @return (-pi, pi] 
     */
    T angleInRad() const
    {
        return std::atan2(y_, x_);
    }

    /**
     * @return (-180.0, 180.0] 
     */
    T angleInDeg() const
    {
        return util::conv::radToDeg(angleInRad());
    }

    bool isZero() const
    {
        return std::fabs(x_) < util::constants::epsilon<T>()
            && std::fabs(y_) < util::constants::epsilon<T>();
    }

    T x_, y_;
};

template <typename T>
bool operator==(const Point2D<T>& lhs, const Point2D<T>& rhs)
{
    return std::fabs(lhs.x_ - rhs.x_) < util::constants::epsilon<T>() 
        && std::fabs(lhs.y_ - rhs.y_) < util::constants::epsilon<T>();
}

template <typename T>
bool operator!=(const Point2D<T>& lhs, const Point2D<T>& rhs)
{
    return !(lhs == rhs);
}

template <typename T>
std::ostream& operator<<(std::ostream& strm, const Point2D<T>& point)
{
    return strm << "(" << point.x_ << "," << point.y_ << ")";
}

using Point2d = Point2D<double>;
using Point2f = Point2D<float>;

using Point2 = Point2D<config::FloatingType>;

} // namespace geometry
} // namespace math

#endif // GEOMETRY_ELEMENTS_POINT2D_HPP_