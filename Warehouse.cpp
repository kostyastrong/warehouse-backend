//
// Created by maincpp on 16.11.2021.
//

#include "Warehouse.h"

#include <random>

Warehouse::Warehouse(int numTypes, int numShops, int sizeCat, int amSize, int def) {  // K, amsize from 1 to 10, def from 1 to 10
    Product::setCatalogue(sizeCat);
    setStorage(amSize);
}



void Warehouse::setStorage(int amSize) {
    for (const auto& i : Product::catalogue) {
        amountMax_[i.first] = 30 + rand() % amSize;
    }
}

void Warehouse::fillStorage(int def) {
    for (const auto& i : Product::catalogue) {
        int num = amountMax_[i.first] * def / 10;
        amountExists_[i.first] = num;
        // Pack byDef = new Pack(Product::catalogue["eggs"], num, 1)
    }
}

void Warehouse::createShops(int numShops) {
    shops_.reserve(numShops);

}


