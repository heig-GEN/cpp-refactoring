// Rental.h
#ifndef RENTAL_H
#define RENTAL_H

#include "Movie.h"

class Rental {
public:
    Rental(const Movie& movie, int daysRented);

    int getDaysRented() const;

    int getFrequentRenterPoints() const;

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

inline const Movie& Rental::getMovie() const { return _movie; }

#endif // RENTAL_H