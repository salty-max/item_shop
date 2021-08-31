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
    std::list<Item> getItems();

    void init(std::string name, int money);
    void printInventory();
    void addItem(Item newItem);
    bool removeItem(std::string itemName, Item &itemToRemove);

private:
    std::string _name;
    int _money;
    std::list<Item> _items;
};