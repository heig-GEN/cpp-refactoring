#ifndef HEIG_GEN_LABO05_CATEGORY_TEST_H
#define HEIG_GEN_LABO05_CATEGORY_TEST_H

#include "gmock/gmock.h"
#include "../Category.h"

using namespace testing;

class MockCategory : public Category {
public:
    MockCategory() : Category(1, 1, 1) {};

    MOCK_METHOD(unsigned, getFrequentRenterPoints, (unsigned days), (override, const));
    MOCK_METHOD(double, getPrice, (unsigned days), (override, const));

};
#endif //HEIG_GEN_LABO05_CATEGORY_TEST_H
