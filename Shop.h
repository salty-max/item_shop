//
// Created by Maxime Blanc on 31/08/2021.
//

#pragma once
#include <string>
#include <list>
#include "Item.h"

class Shop {
public:
    Shop(std::string name, int money);

    std::string getName();
    void setMoney(int money);
    int getMoney() const;

    void printShop();
    bool purchaseItem(std::string itemName, Item &newItem);
    void addItem(Item newItem);
private:
    std::string _name;
    int _money;
    std::list<Item> _items;
};