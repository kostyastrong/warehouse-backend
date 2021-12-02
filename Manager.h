//
// Created by maincpp on 01.12.2021.
//

#ifndef WAREHOUSE_MANAGER_H
#define WAREHOUSE_MANAGER_H
#include<vector>
#include "Application.h"
#include "Shop.h"
#include "Warehouse.h"

class Manager {
public:
    virtual void giveGoods(const std::vector<Application*>&, const std::vector<Shop*>&,
                   const std::unordered_map<std::string, int>&) = 0;  // is it already abstract class?
    virtual void orderGoods(Warehouse*&,
                            const std::unordered_map<std::string, int>&) = 0;
};

class StupidManager {
    
};


#endif //WAREHOUSE_MANAGER_H
