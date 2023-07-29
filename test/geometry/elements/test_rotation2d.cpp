
#include <gtest/gtest.h>

#include <boost/math/constants/constants.hpp>

#include "geometry/elements/rotation2d.hpp"

using namespace math::geometry;

constexpr double PI = boost::math::constants::pi<double>();

TEST(Rotation2D, basic)
{
    {
        Rotation2d rot1(0.0);
        Rotation2d rot2(2.0 * PI);

        EXPECT_TRUE(rot1 == rot2);
    }
    {
        Rotation2d rot1(PI / 2.0);
        Rotation2d rot2(PI / 2.0 + PI * 2.0);

        EXPECT_TRUE(rot1 == rot2);
    }
    {
        Rotation2d rot1(PI / 2.0);
        Rotation2d rot2(PI / 3.0);

        EXPECT_TRUE(rot1 != rot2);
    }
}
