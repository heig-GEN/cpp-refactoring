// Category.h
#ifndef CATEGORY_H
#define CATEGORY_H

class Category {
public:
    virtual double getPrice(unsigned days) const = 0;
};

class Children : public Category {
    double getPrice(unsigned int days) const override {
        double price = 1.5;
        if (days > 3)
            price += (days - 3) * 1.5;
        return price;
    }
};

class NewRelease : public Category {
    double getPrice(unsigned int days) const override {
        return days * 3;
    }
};

class Regular : public Category {
    double getPrice(unsigned int days) const override {
        double price = 2;
        if (days > 2)
            price += (days - 2) * 1.5;
        return price;
    }
};

#endif // CATEGORY_H