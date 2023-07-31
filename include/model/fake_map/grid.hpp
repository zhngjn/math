#ifndef MODEL_FAKE_MAP_GRID_HPP_
#define MODEL_FAKE_MAP_GRID_HPP_

#include "fake_map/grid_data.hpp"

namespace math
{
namespace model
{
namespace fake_map
{
struct GridConfig
{
    bool isValid() const
    {
        return x_resolution_ > 0. && y_resolution_ > 0.
            && x_units_ > 0 && y_units_ > 0
            && x_margin_ >= 0. && x_margin_ < x_resolution_ / 2.0
            && y_margin_ >= 0. && y_margin_ < y_resolution_ / 2.0;
    }

    double x_resolution_, y_resolution_;
    std::size_t x_units_, y_units_;
    double x_margin_, y_margin_;
};

struct Grid
{
    Grid() = default;

    bool isValid() const
    {
        return grid_id_ != INVALID_GRIDID
            && index_ != INVALID_GRIDINDEX;
    }

    GridID grid_id_ = INVALID_GRIDID;
    GridIndex index_ = INVALID_GRIDINDEX;
    GridData data_;
};

} // namespace fake_map
} // namespace model
} // namespace math

#endif // MODEL_FAKE_MAP_GRID_HPP_