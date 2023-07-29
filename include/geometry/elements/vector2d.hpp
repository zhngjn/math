#ifndef GEOMETRY_ELEMENTS_VECTOR2D_HPP_ 
#define GEOMETRY_ELEMENTS_VECTOR2D_HPP_

#include "elements/point2d.hpp"

namespace math
{
namespace geometry 
{

template <typename T>
struct Vector2D 
{
    Vector2D(T x, T y) : x_(x), y_(y) {}
    Vector2D() : Vector2D(T{}, T{}) {}

    Vector2D(const Point2D<T>& p, const Point2D<T>& q) 
        : x_(q.x_ - p.x_), y_(q.y_ - p.y_)
    {}

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

    T dot(const Vector2D<T>& v) const
    {
        return x_ * v.x_ + y_ * v.y_;
    }

    T cross(const Vector2D<T>& v) const
    {
        return x_ * v.y_ - y_ * v.x_;
    }

    T x_, y_;
};

template <typename T>
bool operator==(const Vector2D<T>& lhs, const Vector2D<T>& rhs)
{
    return std::fabs(lhs.x_ - rhs.x_) < util::constants::epsilon<T>() 
        && std::fabs(lhs.y_ - rhs.y_) < util::constants::epsilon<T>();
}

template <typename T>
bool operator!=(const Vector2D<T>& lhs, const Vector2D<T>& rhs)
{
    return !(lhs == rhs);
}

template <typename T>
std::ostream& operator<<(std::ostream& strm, const Vector2D<T>& vector)
{
    return strm << "[" << vector.x_ << "," << vector.y_ << "]";
}

using Vector2d = Vector2D<double>;
using Vector2f = Vector2D<float>;

using Vector2 = Vector2D<config::FloatingType>;

} // namespace geometry
} // namespace math

#endif // GEOMETRY_ELEMENTS_VECTOR2D_HPP_