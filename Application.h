//
// Created by maincpp on 18.11.2021.
//

#ifndef WAREHOUSE_APPLICATION_H
#define WAREHOUSE_APPLICATION_H

#include<string>
#include<unordered_map>
#include"Product.h"

class Report {
public:
    Report();
    Report(const Report&);
    explicit Report(std::unordered_map<std::string, int>& data);
    const std::unordered_map<std::string, int>& getData();

protected:
    std::unordered_map<std::string, int> data_;
};

class Application: public Report {
public:
    Application();
    Application(const Application&);
    explicit Application(std::unordered_map<std::string, int>& data);
    static std::unordered_map<std::string, int> needs_;
    void addProd(std::string, int);

    static void clearNeeds();

private:
    bool added_ = false;
    void add();
};

class Control: public Report {
public:
    Control(std::unordered_map<std::string, int>& data, int type);
    int getType() const;
    // t = 0 for sold, 1 for rotten food, 2 for extra food
private:
    int type_;
};

#endif //WAREHOUSE_APPLICATION_H
