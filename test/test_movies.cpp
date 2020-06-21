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

TEST(movies, setCategoryIsCorrect) {
    MockCategory cat1;
    MockCategory cat2;

    EXPECT_CALL(cat1, getFrequentRenterPoints)
            .Times(AtLeast(2))
            .WillRepeatedly(Return(10));

    EXPECT_CALL(cat2, getFrequentRenterPoints)
            .Times(AtLeast(2))
            .WillRepeatedly(Return(5));

    Movie movie("A", &cat1);
    EXPECT_EQ(movie.getFrequentRenterPoints(1), cat1.getFrequentRenterPoints(1));
    movie.setCategory(&cat2);
    EXPECT_EQ(movie.getFrequentRenterPoints(1), cat2.getFrequentRenterPoints(1));
}