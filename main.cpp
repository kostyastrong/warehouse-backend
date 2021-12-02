#include <iostream>
#include "Product.h"
#include "Shop.h"
#include "Warehouse.h"
#include "Application.h"

Warehouse* warehouse = nullptr;

void newDay(int today) {
    Application::clearNeeds();
    warehouse->throwOld(today);
    warehouse->dailyOrders();

}

int main() {
#ifdef STRONG
    freopen("input.txt", "r", stdin);
#endif

    int numTypes, shops, days;
    std::cin >> numTypes >> shops >> days;

    warehouse = new Warehouse(numTypes, shops, 3);

    for (int day = 1; day <= days; ++day) {
        bool buy = days - day > 1;
        newDay(day);
    }
    std::cout << "tupak's died.";
    return 0;
}
