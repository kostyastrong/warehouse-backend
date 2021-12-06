//
// Created by maincpp on 09.11.2021.
//

#include <algorithm>
#include <random>
#include "Product.h"

Product::Product() = default;
std::unordered_map<std::string, Product*> Product::catalogue;

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
    return price_ * (100 - discount_) / 100;
}

int Pack::untilExpDate(int current) const {
    return current - expDate_;
}

bool Pack::isExpired(int current) {
    return untilExpDate(current) >= 0;
}


Pack::Pack(Product& a, int packages, int today):
    packages_(packages),
    expDate_(a.getLife() + today){
    inPackage_ = a.inPackage();
    shelfLife_ = a.getLife();
    price_ = a.price();
    name_ = a.getName();
    //Product* prt = static_cast<Product*>(this);
    //*prt = *a;
}

int Pack::dateCame() const {
    return expDate_ - shelfLife_;
}

bool Pack::sortByComing(const Pack &a, const Pack &b)  {
    return a.dateCame() < b.dateCame();
}

int Pack::getPackages() const {
    return packages_;
}

int Pack::reducePackages(int num) {
    if (num > packages_) {
        num = packages_;
    }
    packages_ -= num;
    return num;
}

int Pack::calcAmount() const {
    return inPackage_ * packages_;
}

int Pack::discount() const {
    return discount_;
}

void Product::setCatalogue(int numTypes, int sz) {
    int INF = 1000000;
    std::vector<std::pair<std::string, Product*>> source = {
            {"egg",          new Product("egg", 50, 14, 5 + rand() % sz)},
            {"fish",         new Product("fish", 750, 18, 5 + rand() % sz)},
            {"meat",         new Product("meat", 600, 20, 5 + rand() % sz)},
            {"apple",        new Product("apple", 30, 10, 13 + rand() % sz)},
            {"pear",         new Product("pear", 40, 7, 5 + rand() % sz)},
            {"milk",         new Product("milk", 100, 8, 5 + rand() % sz)},
            {"water",        new Product("water", 25, 30, 5 + rand() % sz)},
            {"bread",        new Product("bread", 80, 8, 5 + rand() % sz)},
            {"cake",         new Product("cake", 500, 16, 5 + rand() % sz)},
            {"napkins",      new Product("napkins", 150, INF, 5 + rand() % sz)},
            {"soap",         new Product("soap", 250, INF, 5 + rand() % sz)},
            {"shampoo",      new Product("shampoo", 400, INF, 5 + rand() % sz)},
            {"coal",         new Product("coal", 200, INF, 5 + rand() % sz)},
            {"beer",         new Product("beer", 75, INF, 5 + rand() % sz)},
            {"porrige",      new Product("porrige", 150, 10, 30 + rand() % sz)},
            {"apple juice",  new Product("apple juice", 100, 12, 5 + rand() % sz)},
            {"cherry juice", new Product("cherry juice", 100, 12, 5 + rand() % sz)},
            {"crackers",     new Product("crakers", 5, 100, 5 + rand() % sz)},
            {"domestos",     new Product("domestos", 200, INF, 5 + rand() % sz)},
            {"tomato",       new Product("tomato", 50, 9, 5 + rand() % sz)}
    };

    for (int i = 0; i < numTypes; ++i) {
        Product::catalogue[source[i].first] = source[i].second;
    }
    // std::shuffle(source.begin(), source.end(), std::mt19937(std::random_device()()));
    //Product::catalogue = std::unordered_map<std::string, Product*>(source.begin(), source.begin() + sz);
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

int Product::inPackage() {
    return inPackage_;
}

int Product::calcAmount(int a) const {  // how to name correctly?
    int inPack = Product::catalogue[name_]->inPackage();
    return (a + inPack - 1) / inPack;
}








