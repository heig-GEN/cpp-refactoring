#include <Movie.h>
#include "gtest/gtest.h"

TEST(movies, getTitleIsCorrect) {
    std::string title = "Le Titre";
    Movie movie(title, &NewRelease::INSTANCE);

    ASSERT_EQ(title, movie.getTitle());
}
