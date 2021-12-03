//
// Created by maincpp on 30.11.2021.
//

#ifndef WAREHOUSE_BOOKKEEPING_H
#define WAREHOUSE_BOOKKEEPING_H
#include "Application.h"
#include <unordered_map>

class Bookkeeping {
public:
    explicit Bookkeeping(int days, int shops, int goods);
    void initNamesIndexes();
    void fillVisualZeros(int sz = 90*60*50);
    void csvVisual();
    void daySold(std::vector<Report*>& sold, Control* gener, int today);

private:
    int days_, shops_, goods_;
    std::vector<Application*> applications_;
    std::unordered_map<std::string, int> indexes_;
    std::string revIndexes_[50];
    int visual_[90*60][50];  // days*shops, types of goods
    std::unordered_map<std::string, int> thrown_;
    std::unordered_map<std::string, int> extra_;
    std::unordered_map<std::string, int> sold_;
};


#endif //WAREHOUSE_BOOKKEEPING_H
