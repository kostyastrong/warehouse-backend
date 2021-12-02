//
// Created by maincpp on 16.11.2021.
//

#include "Warehouse.h"

#include <iostream>
#include <random>


std::set<Pack*> Warehouse::bestDiscounts_;

Warehouse::Warehouse(int numTypes, int numShops, int sizeCateg, int amSize, int def):
    size_(amSize),
    numShops_(numShops),
    numTypes_(numTypes) {  // K, amsize from 1 to 10, def from 1 to 10
    Product::setCatalogue(numTypes, sizeCateg);
    setStorage(amSize);
    createShops(numShops);
    fillStorage(def);
}



void Warehouse::setStorage(int amSize) {
    std::unordered_map<std::string, int> tmp;
    for (const auto& i : Product::catalogue) {
        amountMax_[i.first] = 30 + rand() % amSize;
    }
}

void Warehouse::fillStorage(int def) {
    for (const auto& i : Product::catalogue) {
        int num = amountMax_[i.first] * def / 10;
        amountExists_[i.first] = num;
        Pack* byDef = new Pack(*Product::catalogue[i.first], num, 1);
        bestDiscounts_.insert(byDef);
        byCategory_[byDef->getName()].insert(byDef);
    }
}

void Warehouse::createShops(int numShops) {
    shops_ = std::vector<Shop*>(numShops, nullptr);
    for (int i = 0; i < numShops; ++i) {
        shops_[i] = new Shop(4 + rand() % 4);
    }
}

void Warehouse::checkContainers(const int today, const Bookkeeping* taker) {
    std::unordered_map<std::string, int> thrown;
    while (! containers_.empty() && (*containers_.begin())->dateCame() <= today) {
        Pack* tmp = *containers_.begin();
        int inBin = addPack(tmp);
        amountOrdered_[tmp->getName()] -= tmp->getPackages();
        if (inBin > 0) thrown[tmp->getName()] = inBin;
    }
    Control extra(thrown, 2);
}

int Warehouse::addPack(Pack *fresh) {
    const std::string& freshName = fresh->getName();
    amountExists_[freshName] += fresh->getPackages();
    int left = amountExists_[freshName] - amountMax_[freshName],
        ret = std::max(0, left);

    throwExtra(left, freshName);
    return ret;
}

void Warehouse::throwExtra(int left, const std::string& name) {
    while (left > 0) {
        Pack* getOut = nullptr;
        try {
            getOut = *byCategory_[name].begin();
        } catch (...){
            std::cout << "You've just said you have extra goods,\nbut you don't have any of: " << name << '\n';
            return;
        }
        int inBinLocal = getOut->reducePackages(left);
        left -= inBinLocal;
        if (getOut->getPackages() == 0) {
            byCategory_[name].erase(byCategory_[name].begin());
        }
    }
}

void Warehouse::throwOld(const int today) {
    std::unordered_map<std::string, int> thrown;
    for (auto& i : byCategory_) {
        while (! byCategory_[i.first].empty() &&
                (*byCategory_[i.first].begin())->isExpired(today)) {
            Pack * tmp = *byCategory_[i.first].begin();
            thrown[tmp->getName()] += tmp->getPackages();
            byCategory_[i.first].erase(byCategory_[i.first].begin());
        }
    }
    Control extra(thrown, 2);
}

void Warehouse::dailyOrders() {
    Application::clearNeeds();
    std::vector<Application*> orders(numShops_, nullptr);
    std::vector<Application*> gone(numShops_, {});
    int ind = 0;
    for (Shop* i : shops_) {
        Application* curr = i->order(5);  // to order only 5 types
        orders[ind] = curr;  // when do we copy pointer and when do we copy memory
    }

    std::set<std::string> full;
    std::unordered_map<std::string, int> needManager;
    for (std::pair<const std::string, int>& i : Application::needs_) {
        if (i.second <= amountExists_[i.first]) {
            full.insert(i.first);
        } else {
            needManager[i.first] = amountExists_[i.first];
        }
    }
}


void Warehouse::addContainer(Pack *&added) {
    containers_.insert(added);
}

std::unordered_map<std::string, int> &Warehouse::getAmountExist() {
    return amountExists_;
}

void Warehouse::orderFromSupplier(std::string name, int num, int today) {
    Pack* adding = new Pack(*Product::catalogue[name], num, today + 1 + rand() % 5);
    addContainer(adding);
}

std::unordered_map<std::string, int> &Warehouse::getAmountOrdered() {
    return amountOrdered_;
}

std::unordered_map<std::string, int> &Warehouse::getAmountMax() {
    return amountMax_;
}


