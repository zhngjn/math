
#include <gtest/gtest.h>

#include "util/utility.hpp"

using namespace math::util;

TEST(utility, horner)
{
    {
        double v = horner(2.2, 4);
        EXPECT_DOUBLE_EQ(v, 4);
    }
    {
        double v = horner(1.2, 4, 3);
        EXPECT_DOUBLE_EQ(v, 7.6);
    }
    {
        double v = horner(3, 1.1, 2.2, 3.3, 4.4, 5.5);
        EXPECT_DOUBLE_EQ(v, 601.7);
    }
}
