//
// Created by Maxime Blanc on 31/08/2021.
//

#pragma once
#include <string>


class Item {
public:
    Item(std::string name, int pristineValue, int usedValue);
    const std::string &getName() const;
    void setName(const std::string &name);
    int getPristineValue() const;
    void setPristineValue(int value);
    int getUsedValue() const;
    void setUsedValue(int value);
    int getQuantity() const;
    void setQuantity(int quantity);
    void addOne();
    void removeOne();

private:
    std::string _name;
    int _pristineValue;
    int _usedValue;
    int _quantity;
};