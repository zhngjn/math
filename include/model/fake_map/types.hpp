#ifndef MODEL_FAKE_MAP_TYPES_HPP_
#define MODEL_FAKE_MAP_TYPES_HPP_

#include <climits>

#include "geometry/elements/point2d.hpp"
#include "geometry/elements/point2i.hpp"

namespace math
{
namespace model
{
namespace fake_map
{
using NodeID = std::size_t;
using LinkID = std::size_t;
using GridID = std::size_t;

using Coordinate = geometry::Point2d;

using GridIndex = geometry::Point2I<std::size_t>;

constexpr NodeID INVALID_NODEID = std::numeric_limits<NodeID>::max();
constexpr NodeID INVALID_LINKID = std::numeric_limits<LinkID>::max();
constexpr NodeID INVALID_GRIDID = std::numeric_limits<GridID>::max();

const GridIndex INVALID_GRIDINDEX = 
    GridIndex(std::numeric_limits<std::size_t>::max(), 
              std::numeric_limits<std::size_t>::max());

struct Node
{
    Node() = default;
    Node(NodeID node_id, GridID grid_id, const Coordinate& coordinate)
        : node_id_(node_id), grid_id_(grid_id), coordinate_(coordinate)
    {}

    bool isValid() const
    {
        return node_id_ != INVALID_NODEID 
            && grid_id_ != INVALID_GRIDID;
    }

    NodeID node_id_ = INVALID_NODEID;
    GridID grid_id_ = INVALID_GRIDID;
    Coordinate coordinate_;
};

struct Link
{
    Link() = default;
    Link(LinkID link_id, GridID grid_id, NodeID source_node, NodeID target_node)
        : link_id_(link_id), grid_id_(grid_id), 
        source_node_(source_node), target_node_(target_node)
    {}

    bool isValid() const
    {
        return link_id_ != INVALID_LINKID
            && grid_id_ != INVALID_GRIDID
            && source_node_ != INVALID_NODEID
            && target_node_ != INVALID_NODEID;
    }

    LinkID link_id_ = INVALID_LINKID;
    GridID grid_id_ = INVALID_GRIDID;
    NodeID source_node_ = INVALID_NODEID;
    NodeID target_node_ = INVALID_NODEID;
};
} // namespace fake_map
} // namespace model
} // namespace math

#endif // MODEL_FAKE_MAP_TYPES_HPP_