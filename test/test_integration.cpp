#include <iostream>

#include "gtest/gtest.h"

#include "Customer.h"

TEST(integration, statementRemainsIdentical) {
    std::stringstream stream;
    std::string expected;

    expected.append("Rental Record for Olivier\n")
            .append("\tKarate Kid\t9.5\n")
            .append("\tAvengers: Endgame\t15\n")
            .append("\tSnow White\t1.5\n")
            .append("Amount owed is 26\n")
            .append("You earned 4 frequent renter points");

    Customer customer("Olivier");
    customer.addRental(Rental(
            Movie("Karate Kid"), 7)
    );
    customer.addRental(Rental(
            Movie("Avengers: Endgame", Movie::NEW_RELEASE), 5)
    );
    customer.addRental(Rental(
            Movie("Snow White", Movie::CHILDREN), 3)
    );

    stream << customer.statement();

    ASSERT_EQ(expected, stream.str());
}