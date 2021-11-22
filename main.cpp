#include <iostream>
#include "Product.h"
#include "Shop.h"
#include "Warehouse.h"

void init() {
    Warehouse::setCatalogue();

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
