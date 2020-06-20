// Category.h
#ifndef CATEGORY_H
#define CATEGORY_H

class Category {

private:
    double _basePrice;
    double _dailyPrice;

    unsigned _daysCount;
protected:

    explicit Category(double basePrice, double dailyPrice, unsigned daysCount)
            : _basePrice(basePrice), _dailyPrice(dailyPrice),
              _daysCount(daysCount) {}

public:
    double getPrice(unsigned days) const {
        double price = _basePrice;
        if (days > _daysCount) {
            price += (days - _daysCount) * _dailyPrice;
        }
        return price;
    }

    virtual unsigned getFrequentRenterPoints(unsigned days) const {
        return 1;
    }
};

class Children : public Category {
public:
    static Children INSTANCE;

    Children() : Category(1.5, 1.5, 3) {}
};

class NewRelease : public Category {
public:
    static NewRelease INSTANCE;

    NewRelease() : Category(0, 3, 0) {}

    unsigned getFrequentRenterPoints(unsigned int days) const override {
        unsigned points = Category::getFrequentRenterPoints(days);
        return days > 1 ? points + 1 : points;
    }
};

class Regular : public Category {
public:
    static Regular INSTANCE;

    Regular() : Category(2, 1.5, 2) {}
};

#endif // CATEGORY_H