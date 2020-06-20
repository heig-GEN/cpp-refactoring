// Rental.h
#ifndef RENTAL_H
#define RENTAL_H

#include "Movie.h"

class Rental {
public:
    Rental(const Movie& movie, int daysRented);

    int getDaysRented() const;

    int getFrequentRenterPoints() const;

    double getPrice() const;

    const Movie& getMovie() const;

private:
    Movie _movie;
    int _daysRented;
};

inline Rental::Rental(const Movie& movie, int daysRented)
        : _movie(movie), _daysRented(daysRented) {}

inline int Rental::getDaysRented() const { return _daysRented; }

inline int Rental::getFrequentRenterPoints() const {
    if (getMovie().getPriceCode() == Movie::NEW_RELEASE && getDaysRented() > 1)
        return 2;
    else
        return 1;
}

inline double Rental::getPrice() const {
    double thisAmount = 0;
    switch (getMovie().getPriceCode()) {
        case Movie::REGULAR:
            thisAmount += 2;
            if (getDaysRented() > 2)
                thisAmount += (getDaysRented() - 2) * 1.5;
            break;
        case Movie::NEW_RELEASE:
            thisAmount += getDaysRented() * 3;
            break;
        case Movie::CHILDREN:
            thisAmount += 1.5;
            if (getDaysRented() > 3)
                thisAmount += (getDaysRented() - 3) * 1.5;
            break;
    }
    return thisAmount;
}

inline const Movie& Rental::getMovie() const { return _movie; }

#endif // RENTAL_H