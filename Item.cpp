//
// Created by Maxime Blanc on 31/08/2021.
//

#include "Item.h"

Item::Item(std::string name, int value) {
    _name = name;
    _value = value;
    _quantity = 1;
}

const std::string &Item::getName() const {
    return _name;
}
void Item::setName(const std::string &name) {
    _name = name;
}
int Item::getValue() const {
    return _value;
}
void Item::setValue(int value) {
    _value = value;
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
