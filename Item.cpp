//
// Created by Maxime Blanc on 31/08/2021.
//

#include "Item.h"

Item::Item(std::string name, int pristineValue, int usedValue) {
    _name = name;
    _pristineValue = pristineValue;
    _usedValue = usedValue;
    _quantity = 1;
}

const std::string &Item::getName() const {
    return _name;
}
void Item::setName(const std::string &name) {
    _name = name;
}
int Item::getPristineValue() const {
    return _pristineValue;
}
void Item::setPristineValue(int value) {
    _pristineValue = value;
}
int Item::getUsedValue() const {
    return _usedValue;
}
void Item::setUsedValue(int value) {
    _usedValue = value;
}
int Item::getQuantity() const {
    return _quantity;
}
void Item::setQuantity(int quantity) {
    _quantity = quantity;
}

void Item::addOne() {
    _quantity++;
}

void Item::removeOne() {
    _quantity--;
}
