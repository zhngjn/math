
#include <gtest/gtest.h>

#include <boost/math/constants/constants.hpp>

#include "geometry/elements/line2d.hpp"

using namespace math::geometry;

constexpr double PI = boost::math::constants::pi<double>();

TEST(Line2D, valid)
{
    {
        Line2d line;
        EXPECT_FALSE(line.valid());
    }
    {
        Line2d line(Point2d(1, 2), Point2d(3, 4));
        EXPECT_TRUE(line.valid());
    }
}

TEST(Line2D, angleInRad)
{
    Line2d line(Point2d(1, 2), Point2d(3, 4));
    EXPECT_DOUBLE_EQ(line.angleInRad(), PI / 4.0);
}

TEST(Line2D, angleInDeg)
{
    Line2d line(Point2d(1, 2), Point2d(3, 4));
    EXPECT_DOUBLE_EQ(line.angleInDeg(), 45.0);
}