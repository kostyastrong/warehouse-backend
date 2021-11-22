//
// Created by maincpp on 16.11.2021.
//

#ifndef WAREHOUSE_SHOP_H
#define WAREHOUSE_SHOP_H

#include "Product.h"
#include "Application.h"
#include <vector>
#include <algorithm>
#include <random>

class Shop {
public:
    Shop(int size=5);

    Application& order(int choose=10);

    std::vector<int>& randShuffVec(int choose = 10);

private:
    int target_;  // we can specify the goal of a shop
    int size_;  // to have a size of a shop
    int hapiness_;  //
};


#endif //WAREHOUSE_SHOP_H
