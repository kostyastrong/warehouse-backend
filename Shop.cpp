//
// Created by maincpp on 16.11.2021.
//

#include "Shop.h"
#include "Product.h"
#include "Application.h"

#include <random>

Shop::Shop(int size):
        size_(size),
        hapiness_(0),
        target_(0){}

Application* Shop::order(int choose) const {
    int j = 1;

    std::unordered_map<std::string, int> data;
    for (const auto& i : Product::catalogue) {
        int num = rand() % (size_ + 8);
        data[i.first] = i.second->calcAmount(num);
        if (j == choose) break;
        ++j;
    }

    auto* ret = new Application(data);
    return ret;
}

int* Shop::randShuffVec(int choose) {

    int ret = std::max(1, rand() % choose * size_ / rand());
    int* increase = new int[ret];
    int *j = increase;
    for (int i = 0; i < ret; ++i, ++j)  *j = i;
    std::shuffle(increase, increase+ret, std::mt19937(std::random_device()()));

    return increase;
}
