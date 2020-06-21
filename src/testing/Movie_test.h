#ifndef HEIG_GEN_LABO05_MOVIE_TEST_H
#define HEIG_GEN_LABO05_MOVIE_TEST_H

#include <Movie.h>
#include "gmock/gmock.h"
#include "../Category.h"

using namespace testing;

class MockMovie : public Movie {
public:
    MockMovie(const std::string& title, Category* category = &Regular::INSTANCE)
            : Movie(title, category)
            {}

    MOCK_METHOD(unsigned, getFrequentRenterPoints, (int days), (override, const));
    MOCK_METHOD(double, getPrice, (int days), (override, const));
    MOCK_METHOD(void, setCategory, (Category* category), (override));
    MOCK_METHOD(std::string, getTitle, (), (const));
};

#endif //HEIG_GEN_LABO05_MOVIE_TEST_H
