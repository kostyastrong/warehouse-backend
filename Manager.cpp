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
            if (needs[j.first] != 0) {
                int num = std::min(needs[j.first] / Product::catalogue[j.first]->inPackage(),
                                          j.second);
                order[j.first] = num;
                needs[j.first] -= num;
            }
        }
        ret[ind] = new Report(order);
        ++ind;
    }
    return ret;
}
