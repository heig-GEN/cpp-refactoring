#include <iostream>

#include "Customer.h"

int main() {

    Customer customer("Olivier");
    customer.addRental(Rental(
            Movie("Karate Kid"), 7)
    );
    customer.addRental(Rental(
            Movie("Avengers: Endgame", &NewRelease::INSTANCE), 5)
    );
    customer.addRental(Rental(
            Movie("Snow White", &Children::INSTANCE), 3)
    );

    std::cout << customer.statement() << std::endl;

    return 0;
}