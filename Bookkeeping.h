//
// Created by maincpp on 30.11.2021.
//

#ifndef WAREHOUSE_BOOKKEEPING_H
#define WAREHOUSE_BOOKKEEPING_H
#include "Application.h"

class Bookkeeping {
public:
    explicit Bookkeeping(int days);
    void daySold(std::vector<Report*>& sold, Control* gener, int today);

private:
    int days_;
    std::vector<Application*> applications_;
    int vizual_[60][30][30];  // days, shops, types of goods
    std::unordered_map<std::string, int> thrown_;
    std::unordered_map<std::string, int> extra_;
    std::unordered_map<std::string, int> sold_;
};


#endif //WAREHOUSE_BOOKKEEPING_H
