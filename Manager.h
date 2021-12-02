//
// Created by maincpp on 01.12.2021.
//

#ifndef WAREHOUSE_MANAGER_H
#define WAREHOUSE_MANAGER_H
#include <vector>
#include "Application.h"
#include "Shop.h"
#include "Warehouse.h"

class Manager {
public:
    virtual std::vector<Report*> giveGoods(const std::vector<Application*>&, const std::vector<Shop*>&,
                    std::unordered_map<std::string, int>&) = 0;  // is it already abstract class?
    virtual void orderGoods(Warehouse*&, int) = 0;

    virtual void makeSales(Warehouse*&, int) = 0;  // program hadn't worked until I did it virtual
};

class StupidManager: public Manager {
    std::vector<Report*> giveGoods(const std::vector<Application*>&, const std::vector<Shop*>&,
                             std::unordered_map<std::string, int>&) override final;
    void orderGoods(Warehouse*&, int) final;
    void makeSales(Warehouse*&, int) final;
};

#endif //WAREHOUSE_MANAGER_H
