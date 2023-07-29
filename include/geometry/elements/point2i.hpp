#ifndef GEOMETRY_ELEMENTS_POINT2I_HPP_ 
#define GEOMETRY_ELEMENTS_POINT2I_HPP_

#include <ostream>

namespace math
{
namespace geometry 
{

template <typename T>
struct Point2I
{
    Point2I(T x, T y) : x_(x), y_(y) {}
    Point2I() : Point2I(T{}, T{}) {}

    T x_, y_;
};

template <typename T>
bool operator==(const Point2I<T>& lhs, const Point2I<T>& rhs)
{
    return lhs.x_ == rhs.x_ && lhs.y_ == rhs.y_;
}

template <typename T>
bool operator!=(const Point2I<T>& lhs, const Point2I<T>& rhs)
{
    return !(lhs == rhs);
}

template <typename T>
std::ostream& operator<<(std::ostream& strm, const Point2I<T>& point)
{
    return strm << "(" << point.x_ << "," << point.y_ << ")";
}

} // namespace geometry
} // namespace math

#endif // GEOMETRY_ELEMENTS_POINT2I_HPP_