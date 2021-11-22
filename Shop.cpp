//
// Created by maincpp on 16.11.2021.
//

#include "Shop.h"
#include "Product.h"

#include <random>

Shop::Shop(int size):
        size_(size){}

Application& Shop::order(int choose) {
    int j = 0;

    std::unordered_map<std::string, int> data;
    for (auto& i : )
}

std::vector<int> &Shop::randShuffVec(int choose) {

    int ret = std::max(1, rand() % choose * size_ / rand());
    std::vector<int> increase(ret);
    for (int i = 0; i < ret; ++i) increase[i] = i;
    std::shuffle(increase.begin(), increase.end(), std::mt19937(std::random_device()()));

    return increase;
}
