#include <Category.h>
#include "gtest/gtest.h"

TEST(categories, childrenGetPriceIsCorrect) {
    Category category = Children::INSTANCE;
    EXPECT_EQ(1.5, category.getPrice(0));
    EXPECT_EQ(1.5, category.getPrice(1));
    EXPECT_EQ(1.5, category.getPrice(2));
    EXPECT_EQ(1.5, category.getPrice(3));
    EXPECT_EQ(3, category.getPrice(4));
}

TEST(categories, newReleaseGetPriceIsCorrect) {
    Category category = NewRelease::INSTANCE;
    EXPECT_EQ(0, category.getPrice(0));
    EXPECT_EQ(3, category.getPrice(1));
    EXPECT_EQ(6, category.getPrice(2));
    EXPECT_EQ(9, category.getPrice(3));
}

TEST(categories, regularGetPriceIsCorrect) {
    Category category = Regular::INSTANCE;
    EXPECT_EQ(2, category.getPrice(0));
    EXPECT_EQ(2, category.getPrice(1));
    EXPECT_EQ(2, category.getPrice(2));
    EXPECT_EQ(3.5, category.getPrice(3));
    EXPECT_EQ(5, category.getPrice(4));
}
