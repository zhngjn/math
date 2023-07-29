#ifndef GEOMETRY_DUMP_TO_TXT_HPP_ 
#define GEOMETRY_DUMP_TO_TXT_HPP_

#include <fstream>
#include <iomanip>
#include <vector>

#include "elements/point2d.hpp"
#include "elements/vector2d.hpp"

namespace math
{
namespace geometry 
{
namespace dump
{
namespace txt
{
constexpr int DEFAULT_PREC = 6;

/**
 * @brief 
 * @details
 * p.x p.y 
 */
template <typename T>
void dumpPoints(const std::string& path, 
                const std::vector<Point2D<T>>& points, 
                int prec = DEFAULT_PREC)
{
    std::fstream fs(path, std::ios_base::out);
    fs << std::fixed << std::setprecision(prec);

    for (const auto& point : points) {
        fs << point.x_ << " " << point.y_ << std::endl;
    }

    fs.close();
}

/**
 * @brief 
 * @details
 * v.x v.y 
 */
template <typename T>
void dumpVectors(const std::string& path, 
                const std::vector<Vector2D<T>>& vectors,
                int prec = DEFAULT_PREC)
{
    std::fstream fs(path, std::ios_base::out);
    fs << std::fixed << std::setprecision(prec);

    for (const auto& vector : vectors) {
        fs << vector.x_ << " " << vector.y_ << std::endl;
    }

    fs.close();
}

} // namespace txt
} // namespace dump
} // namespace geometry
} // namespace math

#endif // GEOMETRY_DUMP_TO_TXT_HPP_