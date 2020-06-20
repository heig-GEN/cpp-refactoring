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

    Movie(const std::string& title, Category* category = &Regular::INSTANCE);

    unsigned getFrequentRenterPoints(int days) const;

    double getPrice(int days) const;

    Category* getPriceCode() const;

    void setPriceCode(Category* category);

    std::string getTitle() const;

private:
    Category* _category;
    std::string _title;
};

inline Movie::Movie(const std::string& title, Category* category)
        : _title(title), _category(category) {
}

inline unsigned Movie::getFrequentRenterPoints(int days) const {
    return _category->getFrequentRenterPoints(days);
}

inline double Movie::getPrice(int days) const {
    return _category->getPrice(days);
}

inline Category* Movie::getPriceCode() const {
    return _category;
}

inline void Movie::setPriceCode(Category* category) {
    this->_category = category;
}

inline std::string Movie::getTitle() const {
    return _title;
}

#endif // MOVIE_H