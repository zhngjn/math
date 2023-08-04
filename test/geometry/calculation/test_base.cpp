
#include <gtest/gtest.h>

#include "util/constants.hpp"
#include "geometry/calculation/base.hpp"

using namespace math;
using namespace math::geometry;

constexpr double PI = util::constants::PI<double>;

TEST(euclideanDistance, euclideanDistance)
{
    Point2d p1(1, 2), p2(3, 4);
    EXPECT_DOUBLE_EQ(euclideanDistance(p1, p2), std::sqrt(8));
}

TEST(angleInDegree, angleInDegree)
{
    {
        const auto angle_in_deg = angleInDegree(Point2d(0, 0), Point2d(0, 0));
        EXPECT_FALSE(!!angle_in_deg);
    }
    {
        const auto angle_in_deg = angleInDegree(Point2d(0, 0), Point2d(1.0, 1.0));
        EXPECT_DOUBLE_EQ(*angle_in_deg, 45.0);
    }
    {
        const auto angle_in_deg = angleInDegree(Point2d(0, 0), Point2d(-1.0, 1.0));
        EXPECT_DOUBLE_EQ(*angle_in_deg, 135.0);
    }
    {
        const auto angle_in_deg = angleInDegree(Point2d(0, 0), Point2d(-1.0, -1.0));
        EXPECT_DOUBLE_EQ(*angle_in_deg, -135.0);
    }
    {
        const auto angle_in_deg = angleInDegree(Point2d(0, 0), Point2d(1.0, -1.0));
        EXPECT_DOUBLE_EQ(*angle_in_deg, -45.0);
    }
    {
        const auto angle_in_deg = angleInDegree(Point2d(0, 0), Point2d(0, 1.0));
        EXPECT_DOUBLE_EQ(*angle_in_deg, 90.0);
    }
    {
        const auto angle_in_deg = angleInDegree(Point2d(0, 0), Point2d(0, -1.0));
        EXPECT_DOUBLE_EQ(*angle_in_deg, -90.0);
    }
}

TEST(angleInRadian,angleInRadian)
{
    {
        const auto angle_in_rad = angleInRadian(Point2d(0, 0), Point2d(0, 0));
        EXPECT_FALSE(!!angle_in_rad);
    }
    {
        const auto angle_in_rad = angleInRadian(Point2d(0, 0), Point2d(1.0, 1.0));
        EXPECT_DOUBLE_EQ(*angle_in_rad, (1.0 / 4.0) * PI);
    }
    {
        const auto angle_in_rad = angleInRadian(Point2d(0, 0), Point2d(-1.0, 1.0));
        EXPECT_DOUBLE_EQ(*angle_in_rad, (3.0 / 4.0) * PI);
    }
    {
        const auto angle_in_rad = angleInRadian(Point2d(0, 0), Point2d(-1.0, -1.0));
        EXPECT_DOUBLE_EQ(*angle_in_rad, -(3.0 / 4.0) * PI);
    }
    {
        const auto angle_in_rad = angleInRadian(Point2d(0, 0), Point2d(1.0, -1.0));
        EXPECT_DOUBLE_EQ(*angle_in_rad, -(1.0 / 4.0) * PI);
    }
    {
        const auto angle_in_rad = angleInRadian(Point2d(0, 0), Point2d(0, 1.0));
        EXPECT_DOUBLE_EQ(*angle_in_rad, (1.0 / 2.0) * PI);
    }
    {
        const auto angle_in_rad = angleInRadian(Point2d(0, 0), Point2d(0, -1.0));
        EXPECT_DOUBLE_EQ(*angle_in_rad, -(1.0 / 2.0) * PI);
    }
}

TEST(angleInDegree3, angleInDegree3)
{
    {
        const auto angle_in_deg = 
            angleInDegree(Point2d(0, 0), Point2d(0, 1), Point2d(0, 1));
        EXPECT_FALSE(!!angle_in_deg);
    }
    {
        const auto angle_in_deg = 
            angleInDegree(Point2d(0, 0), Point2d(0, 1), Point2d(0, 2));
        EXPECT_DOUBLE_EQ(*angle_in_deg, 0.0);
    }
    {
        const auto angle_in_deg = 
            angleInDegree(Point2d(0, 0), Point2d(0, 1), Point2d(1, 1));
        EXPECT_DOUBLE_EQ(*angle_in_deg, 90.0);
    }
    {
        const auto angle_in_deg = 
            angleInDegree(Point2d(0, 0), Point2d(0, 1), Point2d(0, 0));
        EXPECT_DOUBLE_EQ(*angle_in_deg, 180.0);
    }
    {
        const auto angle_in_deg = 
            angleInDegree(Point2d(0, 0), Point2d(0, 1), Point2d(-1, 1));
        EXPECT_DOUBLE_EQ(*angle_in_deg, 90.0);
    }
    {
        const auto angle_in_deg = 
            angleInDegree(Point2d(0, 0), Point2d(0, 1), Point2d(1, 2));
        EXPECT_DOUBLE_EQ(*angle_in_deg, 45.0);
    }
    {
        const auto angle_in_deg = 
            angleInDegree(Point2d(0, 0), Point2d(0, 1), Point2d(-1, 0));
        EXPECT_DOUBLE_EQ(*angle_in_deg, 135.0);
    }
}

TEST(angleInRadian3, angleInRadian3)
{
    {
        const auto angle_in_deg = 
            angleInRadian(Point2d(0, 0), Point2d(0, 1), Point2d(0, 1));
        EXPECT_FALSE(!!angle_in_deg);
    }
    {
        const auto angle_in_deg = 
            angleInRadian(Point2d(0, 0), Point2d(0, 1), Point2d(0, 2));
        EXPECT_DOUBLE_EQ(*angle_in_deg, 0.0);
    }
    {
        const auto angle_in_deg = 
            angleInRadian(Point2d(0, 0), Point2d(0, 1), Point2d(1, 1));
        EXPECT_DOUBLE_EQ(*angle_in_deg, PI / 2.0);
    }
    {
        const auto angle_in_deg = 
            angleInRadian(Point2d(0, 0), Point2d(0, 1), Point2d(0, 0));
        EXPECT_DOUBLE_EQ(*angle_in_deg, PI);
    }
    {
        const auto angle_in_deg = 
            angleInRadian(Point2d(0, 0), Point2d(0, 1), Point2d(-1, 1));
        EXPECT_DOUBLE_EQ(*angle_in_deg, PI / 2.0);
    }
    {
        const auto angle_in_deg = 
            angleInRadian(Point2d(0, 0), Point2d(0, 1), Point2d(1, 2));
        EXPECT_DOUBLE_EQ(*angle_in_deg, PI / 4.0);
    }
    {
        const auto angle_in_deg = 
            angleInRadian(Point2d(0, 0), Point2d(0, 1), Point2d(-1, 0));
        EXPECT_DOUBLE_EQ(*angle_in_deg, (3.0 / 4.0) * PI);
    }
}