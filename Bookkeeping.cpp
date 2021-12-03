//
// Created by maincpp on 30.11.2021.
//

#include <fstream>
#include "Bookkeeping.h"

Bookkeeping::Bookkeeping(int days, int shops, int goods):
    days_(days),
    shops_(shops),
    goods_(goods){
    initNamesIndexes();
    fillVisualZeros();
}

void Bookkeeping::daySold(std::vector<Report *> &sold, Control *gener, int today) {
    int shopInd = 0;
    for (Report* i : sold) {
        //int* row = *visual_ + (today - 1) * shops_ + shopInd;  // this will be faster
        visual_[(today - 1) * shops_ + shopInd][0] = shopInd;
        visual_[(today - 1) * shops_ + shopInd][1] = today - 1;
        for (const std::pair<const std::string, int>& j : i->getData()) {
            int goodInd = indexes_[j.first];
            visual_[(today - 1) * shops_ + shopInd][goodInd + 2] = j.second;
        }
        ++shopInd;
    }
}

void Bookkeeping::initNamesIndexes() {
    int ind = 0;
    for (const std::string& i: Product::names) {
        revIndexes_[ind] = i;
        indexes_[i] = ind++;
    }
}

void Bookkeeping::fillVisualZeros(int sz) {
    int* i = *visual_;
    for (int j = 0; j < sz; ++j) {
        *i = 0;
        ++i;
    }
}

void Bookkeeping::csvVisual() {
    std::ofstream visual;
    visual.open("data_shops.csv");
    visual << "shop_id,day,";
    for (int ind = 0; ind < goods_; ++ind) {
        visual << revIndexes_[ind];
        if (ind != goods_ - 1) visual << ',';
    }
    visual << '\n';
    for (int i = 0; i < days_; ++i) {
        for (int shopInd = 0; shopInd < shops_; ++shopInd) {
            visual << shopInd << ',' << i << ',';
            for (int j = 2; j < goods_ + 2; ++j) {
                visual << visual_[i * shops_ + shopInd][j];
                if (j != goods_ + 1) visual << ',';
            }
            visual << '\n';
        }

    }
    visual.close();
}

void Bookkeeping::csvGraphics(Warehouse* giver) {
    std::ofstream visual;
    visual.open("data.csv");
    visual << "sold,loss,money,discountLoss,day\n";
    for (int i = 0; i < days_; ++i) {
        visual << std::to_string(giver->sold_[i]) << ',';
        visual << std::to_string(giver->loss_[i]) << ',';
        visual << std::to_string(giver->money_[i]) << ',';
        visual << std::to_string(giver->discountLoss[i]) << ',' << i <<'\n';
    }
    visual.close();
}
