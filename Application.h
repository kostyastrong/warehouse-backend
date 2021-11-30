//
// Created by maincpp on 18.11.2021.
//

#ifndef WAREHOUSE_APPLICATION_H
#define WAREHOUSE_APPLICATION_H

#include<string>
#include<unordered_map>
#include"Product.h"

class Application {
public:
    explicit Application(std::unordered_map<std::string, int> data);
    static void globalApplication(std::unordered_map<std::string, int>& data);
    static std::unordered_map<std::string, int> needs_;
    void add();
    static void clearNeeds();

private:
    bool added_ = false;
    std::unordered_map<std::string, int> data_;
};


#endif //WAREHOUSE_APPLICATION_H
