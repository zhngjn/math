
#include <gtest/gtest.h>

#include <boost/math/constants/constants.hpp>

#include "geometry/elements/segment2d.hpp"

using namespace math::geometry;

constexpr double PI = boost::math::constants::pi<double>();

TEST(Segment2D, valid)
{
    {
        Segment2d segment;
        EXPECT_FALSE(segment.valid());
    }
    {
        Segment2d segment(Point2d(1, 2), Point2d(3, 4));
        EXPECT_TRUE(segment.valid());
    }
}

TEST(Segment2D, length)
{
    Segment2d segment(Point2d(1, 2), Point2d(3, 4));
    EXPECT_DOUBLE_EQ(segment.length(), std::sqrt(8));
}

TEST(Segment2D, angleInRad)
{
    Segment2d segment(Point2d(1, 2), Point2d(3, 4));
    EXPECT_DOUBLE_EQ(segment.angleInRad(), PI / 4.0);
}

TEST(Segment2D, angleInDeg)
{
    Segment2d segment(Point2d(1, 2), Point2d(3, 4));
    EXPECT_DOUBLE_EQ(segment.angleInDeg(), 45.0);
}