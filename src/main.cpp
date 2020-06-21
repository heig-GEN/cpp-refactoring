#include <iostream>

#include "Customer.h"

int main() {
    Movie karate("Karate Kid");
    Movie avengers("Avengers: Endgame", &NewRelease::INSTANCE);
    Movie snow("Snow White", &Children::INSTANCE);

    Customer customer("Olivier");
    customer.addRental(Rental(&karate, 7));
    customer.addRental(Rental(&avengers, 5));
    customer.addRental(Rental(&snow, 3));

    std::cout << customer.statement() << std::endl;

    return 0;
}