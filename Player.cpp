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

void Player::init(std::string name, int money) {
    _name = name;
    _money = money;
}

void Player::printInventory() {
    std::cout << "*** " << _name << "'s inventory ***\n\n";
    std::list<Item>::iterator lit;

    int idx = 1;

    for (lit = _items.begin(); lit != _items.end(); lit++) {
        std::cout << idx << ". " << (*lit).getName() << "x" << (*lit).getQuantity() << std::endl;
        idx++;
    }
}

void Player::addItem(Item newItem) {
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

void Player::removeItem(std::string itemName) {
    std::list<Item>::iterator lit;
    for (lit = _items.begin(); lit != _items.end(); lit++) {
        if ((*lit).getName() == itemName) {
            (*lit).removeOne();

            if ((*lit).getQuantity() == 0) {
                _items.erase(lit);
            }
        }
    }
}
