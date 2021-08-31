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
    std::cout << "\033[1m*** " << _name << "'s inventory ***\033[0m" << std::endl;
    std::cout << "\033[1;34mMoney: " << _money << "G\033[0m" << std::endl;

    std::list<Item>::iterator lit;
    int idx = 1;

   if (!_items.empty()) {
       for (lit = _items.begin(); lit != _items.end(); lit++) {
           std::cout << idx << ". " << (*lit).getName() << " x " << (*lit).getQuantity() << " (" << (*lit).getUsedValue() << "G)" << std::endl;
           idx++;
       }
   } else {
       std::cout << "--- EMPTY ---" << std::endl;
   }

    std::cout << std::endl;
}

bool Player::canAffordItem(std::string itemName, int availableMoney) {
    std::list<Item>::iterator lit;
    for (lit = _items.begin(); lit != _items.end(); lit++) {
        if ((*lit).getName() == itemName) {
            if ((*lit).getUsedValue() <= availableMoney) {
                return true;
            } else return false;
        }
    }
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
