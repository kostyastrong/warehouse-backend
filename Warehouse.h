//
// Created by maincpp on 16.11.2021.
//

#ifndef WAREHOUSE_WAREHOUSE_H
#define WAREHOUSE_WAREHOUSE_H

#include "Product.h"
#include "Application.h"
#include "Bookkeeping.h"
#include "Shop.h"
#include "set"

struct sortByComing {
    bool operator() (const Pack* x, const Pack* y) const {
        return Pack::sortByComing(*x, *y);
    }
};

class Warehouse {
public:
    Warehouse(int numTypes, int numShops, int sizeCateg = 3, int amsize = 15, int def = 5);
    void checkContainers(int today, const Bookkeeping* taker);
    void dailyOrders();
    void throwOld(int today);
    void addContainer(Pack*& added);
    const std::unordered_map<std::string, int>& getAmExist();

    static std::set<Pack*> bestDiscounts_;
    std::unordered_map<std::string, int> amountOrdered_;



private:
    int size_;  // how many goods there are
    int numShops_;
    int numTypes_;
    void setStorage(int amSize = 15);
    void fillStorage(int def = 5);
    void createShops(int numShops);
    void throwExtra(int left, const std::string& name);
    int addPack(Pack* adding);
    std::set<Pack*, sortByComing> containers_;
    std::unordered_map<std::string, std::set<Pack*, sortByComing>> byCategory_;
    std::vector<Shop*> shops_;
    std::unordered_map<std::string, int> amountExists_;
    std::unordered_map<std::string, int> amountMax_;
};


#endif //WAREHOUSE_WAREHOUSE_H
