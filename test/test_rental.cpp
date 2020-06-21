#include <Movie.h>
#include <testing/Movie_test.h>
#include <Rental.h>
#include <testing/Category_test.h>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using ::testing::AtLeast;

TEST(rental, getPriceIsCorrect) {
    int value = 10;
    int days = 10;
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

TEST(rental, getDaysRentedIsCorrect) {
    Movie movie("salut");
    int days = 10;

    Rental rental(&movie, days);
    ASSERT_EQ(days, rental.getDaysRented());
}

TEST(rental, getFrequentRenterPoints) {
    int value = 10;
    int days = 10;
    MockCategory category;

    EXPECT_CALL(category, getFrequentRenterPoints)
            .WillRepeatedly(Return(value));

    MockMovie movie("Title", &category);

    EXPECT_CALL(movie, getFrequentRenterPoints)
            .Times(AtLeast(2))
            .WillRepeatedly(Return(category.getFrequentRenterPoints(days)));

    Rental rental(&movie, days);

    EXPECT_EQ(movie.getFrequentRenterPoints(days), rental.getFrequentRenterPoints());
}
