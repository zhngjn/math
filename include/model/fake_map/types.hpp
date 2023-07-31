#ifndef MODEL_FAKE_MAP_TYPES_HPP_
#define MODEL_FAKE_MAP_TYPES_HPP_

#include <climits>

#include "geometry/elements/point2d.hpp"

namespace math
{
namespace model
{
namespace fake_map
{
using NodeID = std::size_t;
using LinkID = std::size_t;

using Location = geometry::Point2d;

constexpr NodeID INVALID_NODEID = std::numeric_limits<NodeID>::max();
constexpr NodeID INVALID_LINKID = std::numeric_limits<LinkID>::max();

} // namespace fake_map
} // namespace model
} // namespace math

#endif // MODEL_FAKE_MAP_TYPES_HPP_