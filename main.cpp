#include <iostream>
#include "Shop.h"
#include "Player.h"

void initShops(std::list<Shop> &shops);
void initPlayer(Player &player);

int main() {
    std::list<Shop> shops;
    Player player;

    bool isDone = false;

    initShops(shops);
    initPlayer(player);

    getchar();
    return 0;
}

void initShops(std::list<Shop> &shops) {
    shops.emplace_back("Sarah's Little Garden", 500);
    shops.back().addItem(Item("Carrot", 3));
    shops.back().addItem(Item("Potato", 2));
    shops.back().addItem(Item("Rice", 5));
    shops.back().addItem(Item("Melon", 7));

    shops.emplace_back("The Magical Cauldron", 1500);
    shops.back().addItem(Item("Health Potion", 200));
    shops.back().addItem(Item("Mana Potion", 150));
    shops.back().addItem(Item("Love Potion", 700));

    shops.emplace_back("The Burning Anvil", 2000);
    shops.back().addItem(Item("Iron Sword", 50));
    shops.back().addItem(Item("Bronze Boots", 50));
    shops.back().addItem(Item("Bronze Gauntlets", 50));
    shops.back().addItem(Item("Bronze Greaves", 100));
    shops.back().addItem(Item("Bronze Cuirass", 150));
}

void initPlayer(Player &player) {
    std::string name;
    std::cout << "Enter thy name, sir knight: ";
    std::cin >> name;

    player.init(name, 100);
    player.addItem(Item("Oak stick", 1));
}
