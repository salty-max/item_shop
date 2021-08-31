//
// Created by Maxime Blanc on 31/08/2021.
//

#include <iostream>
#include "Shop.h"

Shop::Shop(std::string name, int money) {
    _name = name;
    _money = money;
}

std::string Shop::getName() {
    return _name;
}
void Shop::setMoney(int money) { _money = money; }
int Shop::getMoney() const { return _money; }

void Shop::printShop() {
    std::cout << "*** Welcome to " << _name << " ***\n\n";
    std::list<Item>::iterator lit;

    int idx = 1;

    for (lit = _items.begin(); lit != _items.end(); lit++) {
        std::cout << idx << ". " << (*lit).getName() << "x" << (*lit).getQuantity() << std::endl;
        idx++;
    }
}

bool Shop::purchaseItem(std::string itemName, Item &newItem) {
    std::list<Item>::iterator lit;
    for (lit = _items.begin(); lit != _items.end(); lit++) {
        if ((*lit).getName() == itemName) {
            newItem = (*lit);
            newItem.setQuantity(1);
            (*lit).removeOne();

            if ((*lit).getQuantity() == 0) {
                _items.erase(lit);
            }

            return true;
        }
    }

    return false;
}

void Shop::addItem(Item newItem) {
    std::list<Item>::iterator lit;
    for (lit = _items.begin(); lit != _items.end(); lit++) {
        if ((*lit).getName() == newItem.getName()) {
            (*lit).addOne();
            return;
        } else {
            _items.push_back(newItem);
        }
    }
}
