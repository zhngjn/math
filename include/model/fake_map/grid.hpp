#ifndef MODEL_FAKE_MAP_GRID_HPP_
#define MODEL_FAKE_MAP_GRID_HPP_

#include "geometry/elements/point2i.hpp"

namespace math
{
namespace model
{
namespace fake_map
{
using GridIndex = geometry::Point2I<std::size_t>;

struct GridConfig
{
    double x_resolution_, y_resolution_;
    std::size_t x_units_, y_units_;
    double x_margin_, y_margin_;
};

template <typename GridData>
struct Grid
{
    std::size_t id_;
    GridIndex index_;
    GridData data_;
};

} // namespace fake_map
} // namespace model
} // namespace math

#endif // MODEL_FAKE_MAP_GRID_HPP_