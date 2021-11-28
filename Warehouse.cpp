//
// Created by maincpp on 16.11.2021.
//

#include "Warehouse.h"

#include <random>

Warehouse::Warehouse(int numTypes, int numShops, int sizeCateg, int amSize, int def) {  // K, amsize from 1 to 10, def from 1 to 10
    Product::setCatalogue(sizeCateg);
    setStorage(amSize);
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
        Pack* byDef = new Pack(*Product::catalogue["eggs"], num, 1);
        bestDiscounts_.insert(byDef);
    }
}

void Warehouse::createShops(int numShops) {
    shops_.reserve(numShops);

}

void Warehouse::checkContainers(const int today) {
    Application::clearNeeds();
    std::unordered_map<std::string, int> thrown;
    while (! containers_.empty() && (*containers_.begin())->dateCame()) {
        Pack* tmp = *containers_.begin();
        bestDiscounts_.insert(*containers_.begin());
        if (amountExists_[tmp->getName()] > amountMax_[tmp->getName()]) {

        }
    }
}


