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
    bool canAffordItem(std::string itemName, int playerMoney);
    bool purchaseItem(std::string itemName, Item &itemToSell);
    void addItem(Item newItem);
private:
    std::string _name;
    int _money;
    std::list<Item> _items;
};