//
// Created by maincpp on 16.11.2021.
//

#ifndef WAREHOUSE_WAREHOUSE_H
#define WAREHOUSE_WAREHOUSE_H

#include "Product.h"
#include "Application.h"
#include "Shop.h"
#include "set"

class Warehouse {
public:
    Warehouse(int numTypes, int numShops, int size = 5, int def = 5);

    static void setCatalogue(int sz = 5);
    static std::set<Pack> bestDiscounts;

private:
    int size_;
    std::unordered_map<std::string, int> amountStored;
    std::set
};


#endif //WAREHOUSE_WAREHOUSE_H
