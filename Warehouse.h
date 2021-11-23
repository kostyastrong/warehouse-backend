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
    Warehouse(int numTypes, int numShops, int sizeCat = 3, int amsize = 5, int def = 5);


    static std::set<Pack*> bestDiscounts;

private:
    int size_;
    static void setCatalogue(int sz = 5);
    void setStorage(int amSize = 15);
    void fillStorage(int def = 5);
    void createShops(int numShops);
    std::set<Pack, decltype(Pack::sortByComing)*> containers;
    std::vector<Shop> shops_;
    std::unordered_map<std::string, int> amountExists_;
    std::unordered_map<std::string, int> amountMax_;
};


#endif //WAREHOUSE_WAREHOUSE_H
