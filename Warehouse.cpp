//
// Created by maincpp on 16.11.2021.
//

#include "Warehouse.h"

#include <iostream>
#include <random>


std::set<Pack*> Warehouse::bestDiscounts_;

Warehouse::Warehouse(int numTypes, int numShops, int sizeCateg, int amSize, int def):
    size_(amSize),
    numShops_(numShops),
    numTypes_(numTypes) {  // K, amsize from 1 to 10, def from 1 to 10
    Product::setCatalogue(numTypes, sizeCateg);
    setStorage(amSize);
    createShops(numShops);
    fillStorage(def);
}



void Warehouse::setStorage(int amSize) {
    std::unordered_map<std::string, int> tmp;
    for (const auto& i : Product::catalogue) {
        amountMax_[i.first] = 13 + rand() % amSize;  // Packs of...
    }
}

void Warehouse::fillStorage(int def) {
    for (const auto& i : Product::catalogue) {
        int num = amountMax_[i.first] * def / 10;
        amountExists_[i.first] = num;
        Pack* byDef = new Pack(*Product::catalogue[i.first], num, 1);
        bestDiscounts_.insert(byDef);
        byCategory_[i.first].insert(byDef);
    }
}

void Warehouse::createShops(int numShops) {
    shops_ = std::vector<Shop*>(numShops, nullptr);
    for (int i = 0; i < numShops; ++i) {
        shops_[i] = new Shop(4 + rand() % 4);
    }
}

void Warehouse::checkContainers(const int today, const Bookkeeping* taker) {
    std::unordered_map<std::string, int> thrown;
    while (! containers_.empty() && (*containers_.begin())->dateCame() <= today) {
        Pack* tmp = *containers_.begin();
        int inBin = addPack(tmp);
        amountOrdered_[tmp->getName()] -= tmp->getPackages();
        //amountExists_[tmp->getName()] += tmp->getPackages() - inBin;
        if (inBin > 0) thrown[tmp->getName()] = inBin;
        containers_.erase(containers_.begin());
        byCategory_[tmp->getName()].insert(tmp);
    }
    Control extra(thrown, 2);
}

int Warehouse::addPack(Pack *fresh) {
    std::string freshName = fresh->getName();
    // std::cout << fresh->getName() << '\n';
    amountExists_[freshName] += fresh->getPackages();
    int left = amountExists_[freshName] - amountMax_[freshName],
        ret = std::max(0, left);

    deletePacks(left, freshName);
    return ret;
}

void Warehouse::deletePacks(int left, const std::string& name, const bool sold) {
    std::unordered_map<std::string, int> cost;
    //amountExists_[name] -= left;
    while (left > 0) {
        Pack* getOut = nullptr;
        try {
            getOut = *byCategory_[name].begin();
        } catch (...){
            std::cout << "You've just said you have extra goods,\nbut you don't have any of: " << name << '\n';
            return;
        }

        int inBinLocal = getOut->reducePackages(left);
        amountExists_[name] -= inBinLocal;
        if (sold) {
            money_[today_] += inBinLocal * getOut->price();
            discountLoss[today_] += inBinLocal * getOut->price() * getOut->discount();
            sold_[today_] += getOut->inPackage() * getOut->getPackages();
        } else {
            loss_[today_] += inBinLocal * getOut->price();
        }
        left -= inBinLocal;
        if (getOut->getPackages() == 0) {
            byCategory_[name].erase(byCategory_[name].begin());
        }
    }
}

void Warehouse::throwOld(const int today) {
    std::unordered_map<std::string, int> thrown;
    for (auto& i : byCategory_) {
        while (! byCategory_[i.first].empty() &&
                (*byCategory_[i.first].begin())->isExpired(today)) {
            Pack * tmp = *byCategory_[i.first].begin();
            thrown[tmp->getName()] += tmp->getPackages();
            byCategory_[i.first].erase(byCategory_[i.first].begin());
        }
    }
    Control extra(thrown, 2);
}


void Warehouse::dailyOrders(int today, Manager* current, Bookkeeping* stats) {
    Application::clearNeeds();
    std::vector<Application*> orders(numShops_, nullptr);
    std::vector<Application*> gone(numShops_, {});
    int ind = 0;
    for (Shop* i : shops_) {
        Application* curr = i->order(5);  // to order only 5 types
        orders[ind++] = curr;  // when do we copy pointer and when do we copy memory
    }

    std::set<std::string> full;
    std::unordered_map<std::string, int> needManager;
    for (std::pair<const std::string, int>& i : Application::needs_) {
        int exists = amountExists_[i.first];
        needManager[i.first] = exists;
    }

    std::vector<Report *> rules = current->giveGoods(orders, shops_, needManager);
    Control* gener = new Control(rules);
    sendFood(gener, today);
    stats->daySold(rules, gener, today);
}


void Warehouse::addContainer(Pack *&added) {
    containers_.insert(added);
}

std::unordered_map<std::string, int> &Warehouse::getAmountExist() {
    return amountExists_;
}

void Warehouse::orderFromSupplier(std::string name, int num, int today) {
    Pack* adding = new Pack(*Product::catalogue[name], num, today + 1 + rand() % 5);
    amountOrdered_[name] += num;
    addContainer(adding);
}

std::unordered_map<std::string, int> &Warehouse::getAmountOrdered() {
    return amountOrdered_;
}

std::unordered_map<std::string, int> &Warehouse::getAmountMax() {
    return amountMax_;
}

void Warehouse::sendFood(Control * sold, int today) {
    for (const std::pair<const std::string, int>& i : sold->getData()) {
        deletePacks(i.second, i.first, 1);
    }
}


