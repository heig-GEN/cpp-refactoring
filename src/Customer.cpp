// Customer.cpp
#include <sstream>
#include <vector>
#include "Customer.h"

using std::ostringstream;
using std::vector;

using namespace std;

string Customer::statement() {
    double totalAmount = 0;
    unsigned frequentRenterPoints = 0;
    ostringstream result;
    result << "Rental Record for " << getName() << "\n";

    /*
    for(const Rental& rental : _rentals) {
        // add frequent renter points
        frequentRenterPoints += rental.getFrequentRenterPoints();
        // add amount
        totalAmount += rental.getPrice();

        // show figures for this rental
        result << "\t" << rental.getMovie().getTitle() << "\t"
               << rental.getPrice() << "\n";
    }
     */

    prepareStatement(&totalAmount, &frequentRenterPoints, [&](Rental& rental) {
        result
        << "\t" << rental.getMovie().getTitle()
        << "\t" << rental.getPrice() << "\n";
    });

    // add footer lines
    result << "Amount owed is " << totalAmount << "\n";
    result << "You earned " << frequentRenterPoints
           << " frequent renter points";
    return result.str();
}

void Customer::prepareStatement(
        double* amount,
        unsigned int* frequentPoints,
        std::function<void (Rental& rental)> lambda
) const {
    for (Rental rental : _rentals) {
        *frequentPoints += rental.getFrequentRenterPoints();
        *amount += rental.getPrice();
        lambda(rental);
    }
}
