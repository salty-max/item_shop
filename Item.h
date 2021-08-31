//
// Created by Maxime Blanc on 31/08/2021.
//

#pragma once
#include <string>


class Item {
public:
    Item(std::string name, int value);
    const std::string &getName() const;
    void setName(const std::string &name);
    int getValue() const;
    void setValue(int value);
    int getQuantity() const;
    void setQuantity(int quantity);
    void addOne();
    void removeOne();

private:
    std::string _name;
    int _value;
    int _quantity;
};