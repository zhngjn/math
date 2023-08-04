#ifndef GEOMETRY_CALCULATION_BASE_HPP_ 
#define GEOMETRY_CALCULATION_BASE_HPP_

#include "boost/optional.hpp"

#include "elements/point2d.hpp"

namespace math
{
namespace geometry 
{
double euclideanDistance(const Point2d& p1, const Point2d& p2);

/** 
 * @brief compute angle of ab in degree, range is (-180.0, 180.0]
 */
boost::optional<double> angleInDegree(
    const Point2d& a, const Point2d& b);

/** 
 * @brief compute angle of ab in radian, range is (-pi, pi]
 */
boost::optional<double> angleInRadian(
    const Point2d& a, const Point2d& b);

/** 
 * @brief compute angle of ab and bc in degree, range is [0, 180.0]
 */
boost::optional<double> angleInDegree(
    const Point2d& a, const Point2d& b, const Point2d& c);

/** 
 * @brief compute angle of ab and bc in radian, range is [0, pi]
 */
boost::optional<double> angleInRadian(
    const Point2d& a, const Point2d& b, const Point2d& c);


} // namespace geometry
} // namespace math

#endif // GEOMETRY_CALCULATION_BASE_HPP_