//
// Created by maincpp on 09.11.2021.
//

#ifndef WAREHOUSE_PRODUCT_H
#define WAREHOUSE_PRODUCT_H
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>

class Pack;

class Product {
public:
    Product();

    Product(std::string name, int price, int shelfLife = INT32_MAX, int inPackage = 1);  // for catalogue

    [[nodiscard]] virtual int price() const;

    [[nodiscard]] const std::string& getName() const;

    [[nodiscard]] int getLife() const;

    Product(Product&& a) noexcept;

    Product(const Product& a);

    Product& operator=(Product other);

    friend void swap(Product&a, Product& b);
    static void setCatalogue(int numTypes, int sz);
    int inPackage();
    int calcAmount(int);

    static std::vector<std::string> names;
    static std::unordered_map<std::string, Product*> catalogue;

    //friend class Pack;

    // top 100 selling grocery items: https://businessnes.com/list-of-top-selling-grocery-items-and-tips/

protected:
    int price_ = 0;
    int shelfLife_ = -1; // how much it could be stored
    int inPackage_ = 0;

    std::string name_ = "None";
};


class Pack: public Product {
public:
    static bool sortByComing(const Pack& a, const Pack& b);
    Pack(const Product& a, int packages, int today);
    [[nodiscard]] int dateCame() const;
    bool isExpired(int);
    [[nodiscard]] int untilExpDate(int) const;
    [[nodiscard]] int price() const override;
    [[nodiscard]] int getPackages() const;
    int reducePackages(int);
    friend bool operator<(const Pack& a, const Pack& b);

private:
    int packages_ = 0;
    int expDate_ = -1;  // expiration date
    int discount_ = 0;
    std::string name_;
};

#endif //WAREHOUSE_PRODUCT_H
