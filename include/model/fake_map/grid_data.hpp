#ifndef MODEL_FAKE_MAP_GRID_DATA_HPP_
#define MODEL_FAKE_MAP_GRID_DATA_HPP_

#include <vector>

#include "fake_map/types.hpp"

namespace math
{
namespace model
{
namespace fake_map
{
struct GridData
{
    std::vector<Node> nodes_;
    std::vector<Link> links_;
};

} // namespace fake_map
} // namespace model
} // namespace math

#endif // MODEL_FAKE_MAP_GRID_DATA_HPP_