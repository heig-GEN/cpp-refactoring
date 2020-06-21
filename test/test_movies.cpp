#include <Movie.h>
#include <testing/Category_test.h>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using ::testing::AtLeast;

TEST(movies, getTitleIsCorrect) {
    std::string title = "Le Titre";
    Movie movie(title, &NewRelease::INSTANCE);

    ASSERT_EQ(title, movie.getTitle());
}

TEST(movies, getPriceIsCorrect) {
    MockCategory category;
    EXPECT_CALL(category, getPrice)
            .Times(AtLeast(2))
            .WillRepeatedly(Return(6));

    Movie movieA("A", &category);

    unsigned days = 10;
    EXPECT_EQ(movieA.getPrice(days), category.getPrice(days));
}

TEST(movies, getFrequentRenterPointsIsCorrect) {
    MockCategory category;

    EXPECT_CALL(category, getFrequentRenterPoints)
            .Times(AtLeast(2))
            .WillRepeatedly(Return(10));

    Movie movie("A", &category);
    EXPECT_EQ(movie.getFrequentRenterPoints(1), category.getFrequentRenterPoints(1));
}