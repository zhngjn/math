#ifndef GEOMETRY_ELEMENTS_SEGMENT2D_HPP_ 
#define GEOMETRY_ELEMENTS_SEGMENT2D_HPP_

#include "elements/point2d.hpp"

namespace math
{
namespace geometry 
{

template <typename T>
struct Segment2D 
{
    Segment2D(const Point2D<T>& p, const Point2D<T>& q) : p_(p), q_(q) {}
    Segment2D() {}

    bool valid() const 
    { 
        return p_ != q_; 
    }

    T length() const
    {
        T dx = q_.x_ - p_.x_;
        T dy = q_.y_ - p_.y_;
        return std::sqrt(dx * dx + dy * dy);
    }

    /**
     * @return (-pi, pi] 
     */
    T angleInRad() const
    {
        return std::atan2(q_.y_ - p_.y_, q_.x_ - p_.x_);
    }

    /**
     * @return (-180.0, 180.0] 
     */
    T angleInDeg() const
    {
        return util::conv::radToDeg(angleInRad());
    }

    Point2D<T> p_, q_;
};

template <typename T>
bool operator==(const Segment2D<T>& lhs, const Segment2D<T>& rhs)
{
    return (!lhs.valid() && !rhs.valid())
        || (lhs.valid() && rhs.valid() && lhs.p_ == rhs.p_ && lhs.q_ == rhs.q_);
}

template <typename T>
bool operator!=(const Segment2D<T>& lhs, const Segment2D<T>& rhs)
{
    return !(lhs == rhs);
}

template <typename T>
std::ostream& operator<<(std::ostream& strm, const Segment2D<T>& segment)
{
    return strm << "{" << segment.p_ << "," << segment.q_ << "}";
}

using Segment2d = Segment2D<double>;
using Segment2f = Segment2D<float>;

using Segment2 = Segment2D<config::FloatingType>;

} // namespace geometry
} // namespace math

#endif // GEOMETRY_ELEMENTS_SEGMENT2D_HPP_