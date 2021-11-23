#include <iostream>
#include "Product.h"
#include "Shop.h"
#include "Warehouse.h"

Warehouse* warehouse = nullptr;

void newDay() {
    Application::clearNeeds();
}

int main() {
    int numTypes, shops, days;
    std::cin >> numTypes >> shops >> days;

    for (int day = 1; day <= days; ++day) {

        if (days - day <= 1) {
        }
    }
    return 0;
}
