//
// Created by maincpp on 09.11.2021.
//

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

int Pack::allPackages_ = 0;

Pack::Pack(const Product& a, int packages, int today):
    name_(std::move(a.getName())), // mok
    packages_(packages),
    expDate_(a.getLife() + today){}

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








