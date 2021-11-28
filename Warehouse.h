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
    Warehouse(int numTypes, int numShops, int sizeCateg = 3, int amsize = 15, int def = 5);
    void checkContainers(int today);
    static std::set<Pack*> bestDiscounts_;


private:
    int size_;
    void setStorage(int amSize = 15);
    void fillStorage(int def = 5);
    void createShops(int numShops);
    void throwExtra(int left, const std::string& name);
    int addPack(Pack* adding);
    void throwOld();
    std::set<Pack*, decltype(Pack::sortByComing)*> containers_;
    std::unordered_map<std::string, std::set<Pack*, decltype(Pack::sortByComing)>> byCategory_(Pack::sortByComing);
    std::vector<Shop> shops_;
    std::unordered_map<std::string, int> amountExists_;
    std::unordered_map<std::string, int> amountMax_;
};


#endif //WAREHOUSE_WAREHOUSE_H
