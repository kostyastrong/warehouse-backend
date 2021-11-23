//
// Created by maincpp on 09.11.2021.
//

#include <algorithm>
#include <random>
#include "Product.h"

Product::Product() = default;

Product::Product(std::string name, int price, int shelfLife, int inPackage):
    name_(std::move(name)),
    price_(price),
    inPackage_(inPackage),
    shelfLife_(shelfLife){}

int Product::price() const {
    return price_;
}

std::string Product::getName() const{
    return name_;
}

int Product::getLife() const {
    return shelfLife_;
}

Product::Product(const Product& a) {
    name_ = a.name_;
    shelfLife_ = a.shelfLife_;
    price_ = a.price_;
    inPackage_ = a.inPackage_;
}

void swap(Product&a, Product& b) {
    using std::swap;

    swap(a.name_, b.name_);
    swap(a.inPackage_, b.inPackage_);
    swap(a.shelfLife_, b.shelfLife_);
    swap(a.price_, b.price_);
}

Product& Product::operator=(Product other) {
    swap(*this, other);
    return *this;
}


bool operator<(const Pack &a, const Pack &b) {
    if (a.discount_ != b.discount_) return a.discount_ < b.discount_;
    return a.expDate_ < b.expDate_;
}

Product::Product(Product&& a) noexcept {
    name_ = std::move(a.name_);
    shelfLife_ = a.shelfLife_;
    price_ = a.price_;
    inPackage_ = a.inPackage_;
}

int Pack::price() const {
    return price_ * discount_ / 100;
}

int Pack::untilExpDate(int current) {
    return current - expDate_;
}

bool Pack::isExpired(int current) {
    return untilExpDate(current) >= 0;
}


Pack::Pack(const Product& a, int packages, int today):
    name_(std::move(a.getName())), // mok
    packages_(packages),
    expDate_(a.getLife() + today){}

int Pack::dateCame() const {
    return expDate_ - shelfLife_;
}

bool Pack::sortByComing(const Pack &a, const Pack &b)  {
    return a.dateCame() < b.dateCame();
}

void Product::setCatalogue(int sz) {
    int INF = 1000000;
    std::vector<std::pair<std::string, const Product&>> source = {
            {"egg",          Product("egg", 50, 14, 5 + rand() % sz)},
            {"fish",         Product("fish", 750, 18, 5 + rand() % sz)},
            {"meat",         Product("meat", 600, 20, 5 + rand() % sz)},
            {"apple",        Product("apple", 30, 7, 13 + rand() % sz)},
            {"pear",         Product("pear", 40, 7, 5 + rand() % sz)},
            {"milk",         Product("milk", 100, 8, 5 + rand() % sz)},
            {"water",        Product("water", 25, 30, 5 + rand() % sz)},
            {"bread",        Product("bread", 80, 8, 5 + rand() % sz)},
            {"cake",         Product("cake", 500, 16, 5 + rand() % sz)},
            {"napkins",      Product("napkins", 150, INF, 5 + rand() % sz)},
            {"soap",         Product("soap", 250, INF, 5 + rand() % sz)},
            {"shampoo",      Product("shampoo", 400, INF, 5 + rand() % sz)},
            {"coal",         Product("coal", 200, INF, 5 + rand() % sz)},
            {"beer",         Product("beer", 75, INF, 5 + rand() % sz)},
            {"porrige",      Product("porrige", 150, 10, 30 + rand() % sz)},
            {"apple juice",  Product("apple juice", 100, 12, 5 + rand() % sz)},
            {"cherry juice", Product("cherry juice", 100, 12, 5 + rand() % sz)},
            {"crackers",     Product("crakers", 5, 100, 5 + rand() % sz)},
            {"domestos",     Product("domestos", 200, INF, 5 + rand() % sz)},
            {"tomato",       Product("tomato", 50, 9, 5 + rand() % sz)}
    };

    std::shuffle(source.begin(), source.end(), std::mt19937(std::random_device()()));
    Product::catalogue = std::unordered_map<std::string, const Product&>(source.begin(), source.begin() + sz);
}


std::vector<std::string> Product::names {
        "egg",
        "fish",
        "meat",
        "apple",
        "pear",
        "milk",
        "water",
        "bread",
        "cake",
        "napkins",
        "soap",
        "shampoo",
        "coal",
        "beer",
        "porrige",
        "apple juice",
        "cherry juice",
        "crakers",
        "domestos",
        "tomato"
};








