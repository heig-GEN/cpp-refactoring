// Rental.h
#ifndef RENTAL_H
#define RENTAL_H

#include "Movie.h"

class Rental {
public:
    Rental(const Movie& movie, int daysRented);

    virtual int getDaysRented() const;

    virtual unsigned getFrequentRenterPoints() const;

    virtual double getPrice() const;

    virtual const Movie& getMovie() const;

private:
    Movie _movie;
    int _daysRented;
};

inline Rental::Rental(const Movie& movie, int daysRented)
        : _movie(movie),
        _daysRented(daysRented)
        {}

inline int Rental::getDaysRented() const { return _daysRented; }

inline unsigned Rental::getFrequentRenterPoints() const {
    return getMovie().getFrequentRenterPoints(getDaysRented());
}

inline double Rental::getPrice() const {
    return _movie.getPrice(_daysRented);
}

inline const Movie& Rental::getMovie() const { return _movie; }

#endif // RENTAL_H