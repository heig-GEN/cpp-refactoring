#include "gtest/gtest.h"
#include "example.h"

TEST(addition, worksWithPositiveOperands) {
    int a = 15;
    int b = 27;

    ASSERT_EQ(42, addition(a, b));
}