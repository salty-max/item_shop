//
// Created by Maxime Blanc on 31/08/2021.
//

#pragma once

#include <iostream>
#include <string>
#include <list>

#include "Item.h"

class Player {
public:
    std::string getName() const;
    void setName(std::string name);
    int getMoney() const;
    void setMoney(int money);

    void init(std::string name, int money);
    void printInventory();
    void addItem(Item newItem);
    void removeItem(std::string itemName);

private:
    std::string _name;
    int _money;
    std::list<Item> _items;
};