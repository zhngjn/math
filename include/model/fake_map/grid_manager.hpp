#ifndef MODEL_FAKE_MAP_GRID_MANAGER_HPP_
#define MODEL_FAKE_MAP_GRID_MANAGER_HPP_

#include <stdexcept>

#include "fake_map/grid.hpp"

namespace math
{
namespace model
{
namespace fake_map
{
class GridManager
{
public:
    GridManager(const GridConfig& grid_config)
        : grid_config_(grid_config)
    {
        if (!grid_config_.isValid()) {
            throw std::runtime_error("Invalid grid config");
        }

        initGrids();
    }

private:
    void initGrids()
    {
        
    }

private:
    GridConfig grid_config_;
    std::vector<Grid> grids_;
};

} // namespace fake_map
} // namespace model
} // namespace math

#endif // MODEL_FAKE_MAP_GRID_MANAGER_HPP_