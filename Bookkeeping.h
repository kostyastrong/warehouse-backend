//
// Created by maincpp on 30.11.2021.
//

#ifndef WAREHOUSE_BOOKKEEPING_H
#define WAREHOUSE_BOOKKEEPING_H
#include "Application.h"

class Bookkeeping {
public:
    explicit Bookkeeping(int days);

private:
    int days_;
    std::vector<Application*> applications_;
    std::unordered_map<std::string, int> thrown;
    std::unordered_map<std::string, int> extra;
    std::unordered_map<std::string, int> sold;
};


#endif //WAREHOUSE_BOOKKEEPING_H
