// Movie.h
#ifndef MOVIE_H
#define MOVIE_H

#include <string>

#include "Category.h"

class Movie {
public:
    static const int CHILDREN = 2;
    static const int REGULAR = 0;
    static const int NEW_RELEASE = 1;

    Movie(const std::string& title, int priceCode = REGULAR);

    double getPrice(int days) const;

    int getPriceCode() const;

    void setPriceCode(int arg);

    std::string getTitle() const;

private:
    Category* _category;
    std::string _title;
    int _priceCode;
};

inline Movie::Movie(const std::string& title, int priceCode)
        : _title(title), _priceCode(priceCode), _category(nullptr) {
    setPriceCode(priceCode);
}

inline double Movie::getPrice(int days) const {
    return _category->getPrice(days);
}

inline int Movie::getPriceCode() const {
    return _priceCode;
}

inline void Movie::setPriceCode(int arg) {
    _priceCode = arg;

    switch (arg) {
        case Movie::REGULAR:
            this->_category = &Regular::INSTANCE;
            break;
        case Movie::NEW_RELEASE:
            this->_category = &NewRelease::INSTANCE;
            break;
        case Movie::CHILDREN:
            this->_category = &Children::INSTANCE;
            break;
    }
}

inline std::string Movie::getTitle() const {
    return _title;
}

#endif // MOVIE_H