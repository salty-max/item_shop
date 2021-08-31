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
    std::cout << "*** Welcome to " << _name << " ***" << std::endl;
    std::list<Item>::iterator sit;

    int idx = 1;

    for (sit = _items.begin(); sit != _items.end(); sit++) {
        std::cout << idx << ". " << (*sit).getName() << " x " << (*sit).getQuantity() << " (" << (*sit).getValue() << "G)" << std::endl;
        idx++;
    }

    std::cout << std::endl;
}

bool Shop::purchaseItem(std::string itemName, Item &itemToSell) {
    std::list<Item>::iterator lit;
    for (lit = _items.begin(); lit != _items.end(); lit++) {
        if ((*lit).getName() == itemName) {
            itemToSell = (*lit);
            itemToSell.setQuantity(1);
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
        }
    }

    _items.push_back(newItem);
}
