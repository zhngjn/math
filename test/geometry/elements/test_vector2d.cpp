
#include <gtest/gtest.h>

#include <boost/math/constants/constants.hpp>

#include "geometry/elements/vector2d.hpp"

using namespace math::geometry;

constexpr double PI = boost::math::constants::pi<double>();

TEST(Vector2D, norm)
{
    Vector2d v(1, 2);

    EXPECT_DOUBLE_EQ(v.norm(), std::sqrt(5));
}

TEST(Vector2D, angleInRad)
{
    Vector2d v(1, std::sqrt(3));

    EXPECT_DOUBLE_EQ(v.angleInRad(), 1.0 / 3 * PI);
}

TEST(Vector2D, angleInDeg)
{
    Vector2d v(1, std::sqrt(3));

    EXPECT_DOUBLE_EQ(v.angleInDeg(), 60.0);
}

TEST(Vector2D, dot)
{
    Vector2d v1(1, 2), v2(5, 6);

    EXPECT_DOUBLE_EQ(v1.dot(v2), 17);
}

TEST(Vector2D, cross)
{
    Vector2d v1(1, 2), v2(5, 6);

    EXPECT_DOUBLE_EQ(v1.cross(v2), -4);
}
