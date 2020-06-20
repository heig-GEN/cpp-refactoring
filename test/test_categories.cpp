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
