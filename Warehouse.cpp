//
// Created by maincpp on 16.11.2021.
//

#include "Warehouse.h"

#include <random>

Warehouse::Warehouse(int numTypes, int numShops, int size, int def) {  // K, size from 1 to 10, def from 1 to 10

}

void Warehouse::setCatalogue(int sz) {
    int INF = 1000000;
    std::vector<std::pair<std::string, const Product&>> source = {
            {"egg",          Product("egg", 50, 14, 5 + rand() % sz)},
            {"fish",         Product("fish", 750, 18, 5 + rand() % sz)},
            {"meat",         Product("meat", 600, 20, 5 + rand() % sz)},
            {"apple",        Product("apple", 30, 7, 13 + rand() % sz)},
            {"pear",         Product("pear", 40, 7, 5 + rand() % sz)},
            {"milk",         Product("milk", 100, 8, 5 + rand() % sz)},
            {"water",        Product("water", 25, 30, 5 + rand() % sz)},
            {"bread",        Product("bread", 80, 8, 5 + rand() % sz)},
            {"cake",         Product("cake", 500, 16, 5 + rand() % sz)},
            {"napkins",      Product("napkins", 150, INF, 5 + rand() % sz)},
            {"soap",         Product("soap", 250, INF, 5 + rand() % sz)},
            {"shampoo",      Product("shampoo", 400, INF, 5 + rand() % sz)},
            {"coal",         Product("coal", 200, INF, 5 + rand() % sz)},
            {"beer",         Product("beer", 75, INF, 5 + rand() % sz)},
            {"porrige",      Product("porrige", 150, 10, 30 + rand() % sz)},
            {"apple juice",  Product("apple juice", 100, 12, 5 + rand() % sz)},
            {"cherry juice", Product("cherry juice", 100, 12, 5 + rand() % sz)},
            {"crackers",     Product("crakers", 5, 100, 5 + rand() % sz)},
            {"domestos",     Product("domestos", 200, INF, 5 + rand() % sz)},
            {"tomato",       Product("tomato", 50, 9, 5 + rand() % sz)}
    };

    std::shuffle(source.begin(), source.end(), std::mt19937(std::random_device()()));
    Product::catalogue = std::unordered_map<std::string, const Product&>(source.begin(), source.begin() + sz);

}


