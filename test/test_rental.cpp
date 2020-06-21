#include <Movie.h>
#include <testing/Movie_test.h>
#include <Rental.h>
#include <testing/Category_test.h>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using ::testing::AtLeast;

TEST(rental, getPriceIsCorrect) {
    int value = 10;
    unsigned days = 10;
    MockCategory category;

    EXPECT_CALL(category, getPrice)
            .WillRepeatedly(Return(value));

    MockMovie movie("Title", &category);

    EXPECT_CALL(movie, getPrice)
            .Times(AtLeast(1))
            .WillRepeatedly(Return(category.getPrice(days)));

    Rental rental(&movie, days);

    EXPECT_EQ(value, rental.getPrice());
}

