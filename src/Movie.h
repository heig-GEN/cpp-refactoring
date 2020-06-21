// Movie.h
#ifndef MOVIE_H
#define MOVIE_H

#include <string>

#include "Category.h"

class Movie {
public:
    Movie(const std::string& title, Category* category = &Regular::INSTANCE);

    virtual unsigned getFrequentRenterPoints(int days) const;

    virtual double getPrice(int days) const;

    virtual void setCategory(Category* category);

    virtual std::string getTitle() const;

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

inline void Movie::setCategory(Category* category) {
    this->_category = category;
}

inline std::string Movie::getTitle() const {
    return _title;
}

#endif // MOVIE_H