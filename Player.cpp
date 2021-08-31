//
// Created by Maxime Blanc on 31/08/2021.
//

#include "Player.h"

std::string Player::getName() const {
    return _name;
}
void Player::setName(std::string name) {
    _name = name;
}
int Player::getMoney() const {
    return _money;
}
void Player::setMoney(int money) {
    _money = money;
}
std::list<Item> Player::getItems() {
    return _items;
}

void Player::init(std::string name, int money) {
    _name = name;
    _money = money;
}

void Player::printInventory() {
    std::cout << "*** " << _name << "'s inventory ***" << std::endl;

    std::list<Item>::iterator lit;
    int idx = 1;

   if (!_items.empty()) {
       for (lit = _items.begin(); lit != _items.end(); lit++) {
           std::cout << idx << ". " << (*lit).getName() << " x " << (*lit).getQuantity() << std::endl;
           idx++;
       }
   } else {
       std::cout << "--- EMPTY ---" << std::endl;
   }

    std::cout << std::endl;
}

void Player::addItem(Item newItem) {
    std::list<Item>::iterator lit;

    for (lit = _items.begin(); lit != _items.end(); lit++) {
        if ((*lit).getName() == newItem.getName()) {
            (*lit).addOne();
            return;
        }
    }

    _items.push_back(newItem);
}

bool Player::removeItem(std::string itemName, Item &itemToRemove) {
    std::list<Item>::iterator lit;
    for (lit = _items.begin(); lit != _items.end(); lit++) {
        if ((*lit).getName() == itemName) {
            itemToRemove = (*lit);
            itemToRemove.setQuantity(1);
            (*lit).removeOne();

            if ((*lit).getQuantity() == 0) {
                _items.erase(lit);
            }

            return true;
        }
    }

    return false;
}
