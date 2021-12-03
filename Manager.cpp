//
// Created by maincpp on 01.12.2021.
//

#include "Manager.h"


std::vector<Report*> StupidManager::giveGoods(const std::vector<Application *> & orders, const std::vector<Shop*> & shops,
                               std::unordered_map<std::string, int> & needs) {
    std::vector<Report *> ret = std::vector<Report *>(orders.size(), nullptr);
    int ind = 0;
    for (Application* i : orders) {
        std::unordered_map<std::string, int> order = i->getData();
        for (const std::pair<const std::string, int>& j : order) {
            if (j.second == 0) continue;
            int num = std::min(needs[j.first],
                               j.second);
            order[j.first] = num;
            needs[j.first] -= num;
        }
        ret[ind] = new Report(order);
        ++ind;
    }
    return ret;
}

void StupidManager::orderGoods(Warehouse *& warehouse, int today) {
    std::unordered_map<std::string, int>& amountMax_ = warehouse->getAmountMax();
    std::unordered_map<std::string, int>& amountOrdered_ = warehouse->getAmountOrdered();
    std::unordered_map<std::string, int>& amountExists_ = warehouse->getAmountExist();

    for (const std::pair<std::string, int> i : amountMax_) {
        int num = i.second - amountOrdered_[i.first] - amountExists_[i.first];
        if (num == 0) continue;
        warehouse->orderFromSupplier(i.first, num, today);
    }
}

void StupidManager::makeSales(Warehouse *& warehouse, int today) {
    // he doesn't do any sales, he sells old food:)
}
