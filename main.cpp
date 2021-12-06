#include <iostream>
#include "Product.h"
#include "Shop.h"
#include "Warehouse.h"
#include "Application.h"
#include "Manager.h"

Warehouse* warehouse = nullptr;
StupidManager* stupid = new StupidManager();
Bookkeeping* statistics = nullptr;

void newDay(int today) {
    Application::clearNeeds();
    warehouse->today_ = today;
    warehouse->throwOld(today);
    warehouse->dailyOrders(today, stupid, statistics);
    warehouse->checkContainers(today, statistics);
    std::cout << today<< std::endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    int numTypes, shops, days;
    std::cin >> numTypes >> shops >> days;
    std::cout << 0<< std::endl;

    warehouse = new Warehouse(numTypes, shops, 6);
    statistics = new Bookkeeping(days, shops, numTypes);

    for (int day = 1; day <= days; ++day) {
        bool buy = days - day > 1;
        newDay(day);
        if (buy) {
            stupid->orderGoods(warehouse, day);
        }
    }
    statistics->csvVisual();
    statistics->csvGraphics(warehouse);
    std::cout << "tupak's died.";
    return 0;
}
