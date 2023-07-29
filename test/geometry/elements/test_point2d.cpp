
#include <gtest/gtest.h>

#include <boost/math/constants/constants.hpp>

#include "geometry/elements/point2d.hpp"

using namespace math::geometry;

constexpr double PI = boost::math::constants::pi<double>();

TEST(Point2D, norm)
{
    Point2d p(1, 2);

    EXPECT_DOUBLE_EQ(p.norm(), std::sqrt(5));
}

TEST(Point2D, angleInRad)
{
    Point2d p(1, std::sqrt(3));

    EXPECT_DOUBLE_EQ(p.angleInRad(), 1.0 / 3 * PI);
}

TEST(Point2D, angleInDeg)
{
    Point2d p(1, std::sqrt(3));

    EXPECT_DOUBLE_EQ(p.angleInDeg(), 60.0);
}