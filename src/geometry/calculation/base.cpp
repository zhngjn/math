#include "calculation/base.hpp"
#include "util/constants.hpp"

namespace math
{
namespace geometry 
{
namespace
{
constexpr double PI = util::constants::PI<double>;
} // namespace

double euclideanDistance(const Point2d& p1, const Point2d& p2)
{
    double dx = p2.x_ - p1.x_;
    double dy = p2.y_ - p1.y_;

    return std::sqrt(dx * dx + dy * dy);
}

boost::optional<double> angleInDegree(
    const Point2d& a, const Point2d& b)
{
    const auto angle_in_rad = angleInRadian(a, b);
    if (!angle_in_rad)
        return boost::none;
        
    double angle_in_deg = *angle_in_rad * util::constants::RAD_TO_DEG<double>;
    if (angle_in_deg <= -180.0)
        angle_in_deg = -180.0 + DBL_EPSILON;
    if (angle_in_deg > 180.0)
        angle_in_deg = 180.0;

    return angle_in_deg;
}

boost::optional<double> angleInRadian(
    const Point2d& a, const Point2d& b)
{
    if (a == b) 
        return boost::none;
    
    double dx = b.x_ - a.x_;
    double dy = b.y_ - a.y_;

    return std::atan2(dy, dx);
}

boost::optional<double> angleInDegree(
    const Point2d& a, const Point2d& b, const Point2d& c)
{
    const auto angle_in_rad = angleInRadian(a, b, c);
    if (!angle_in_rad)
        return boost::none;

    double angle_in_deg = *angle_in_rad * util::constants::RAD_TO_DEG<double>;
    if (angle_in_deg < 0.0)
        angle_in_deg = 0.0;
    if (angle_in_deg > 180.0)
        angle_in_deg = 180.0;
        
    return angle_in_deg;
}

boost::optional<double> angleInRadian(
    const Point2d& a, const Point2d& b, const Point2d& c)
{
    const auto angle1 = angleInRadian(a, b);
    const auto angle2 = angleInRadian(b, c);
    if (!angle1 || !angle2)
        return boost::none;

    double angle = *angle2 - *angle1;
    while (angle < 0.0)
        angle += PI * 2.0;
    while (angle >= PI * 2.0)
        angle -= PI * 2.0;
    if (angle > PI)
        angle = PI * 2.0 - angle;
    
    return angle;
}

} // namespace geometry
} // namespace math