#include <iostream>
#include "Shop.h"
#include "Player.h"

void setScenery();
void initShops(std::list<Shop> &shops);
void initPlayer(Player &player);
void printShops(std::list<Shop> &shops);
void enterShop(Player &player, Shop &shop);

int main() {
    std::list<Shop> shops;
    Player player;
    std::string shopName;
    std::list<Shop>::iterator sit;

    bool isDone = false;

    setScenery();

    initShops(shops);
    initPlayer(player);

    while(!isDone) {
        printShops(shops);

        std::cout << "Which shop do you want to enter: ";
        getline(std::cin, shopName);
        std::cout << std::endl;

        bool validShop = false;

        for(sit = shops.begin(); sit != shops.end(); sit++) {
            if ((*sit).getName() == shopName) {
                enterShop(player, (*sit));
                validShop = true;
            }
        }

        if (!validShop) {
            std::cout << "Invalid shop name!" << std::endl;
        }
    }

    getchar();
    return 0;
}

void setScenery() {
    std::cout << "*************************************************" << std::endl;
    std::cout << "*\033[1;35m           Shut up and take my money           \033[0m*" << std::endl;
    std::cout << "* A epic tale coded by \033[1;35mMaxime <salty_max> Blanc\033[0m *" << std::endl;
    std::cout << "*************************************************\n\n";
    std::cout << "You are now walking for days in a foreign land." << std::endl;
    std::cout << "You got robbed by bandits just an hour ago. They left you nothing, not even clothes..." << std::endl;
    std::cout << "But fortunately, you can see at the end of the road the walls of a little town" << std::endl;
    std::cout << "You gather what remains of your strength to reach the gates. Arrived after what seems an eternity, you are stopped by a guard by the gate:\n\n";
}

void initShops(std::list<Shop> &shops) {
    shops.emplace_back("Sarah's Little Garden", 250);
    shops.back().addItem(Item("Carrot", 3, 1));
    shops.back().addItem(Item("Potato", 2, 1));
    shops.back().addItem(Item("Rice", 5, 1));
    shops.back().addItem(Item("Melon", 7, 1));

    shops.emplace_back("The Magical Cauldron", 1500);
    shops.back().addItem(Item("Health Potion", 200, 100));
    shops.back().addItem(Item("Mana Potion", 150, 75));
    shops.back().addItem(Item("Love Potion", 700, 350));

    shops.emplace_back("The Burning Anvil", 2000);
    shops.back().addItem(Item("Iron Sword", 50, 25));
    shops.back().addItem(Item("Bronze Boots", 50, 25));
    shops.back().addItem(Item("Bronze Gauntlets", 50, 25));
    shops.back().addItem(Item("Bronze Greaves", 100, 50));
    shops.back().addItem(Item("Bronze Cuirass", 150, 75));
}

void initPlayer(Player &player) {
    std::string name;
    std::cout << "\033[1;33mHalt you nudist!\033[0m What is thy name: ";
    getline(std::cin, name);

    player.init(name, 100);
    player.addItem(Item("Oak Stick", 15, 5));

    std::cout << "You explained the situation and gave your name." <<std::endl;
    std::cout << "Thank you sir \033[1;32m" << player.getName() << "\033[0m and welcome to \033[1;34m<insert boring town name here>\033[0m! \n\n";
    std::cout << "Inside the lively city, you can see various shops." << std::endl;
    std::cout << "Because you are farsighted, you always keep a little money hidden in your underwear in case something goes wrong. You thank your late mom for her good advice and decide to go shopping...\n\n";
}

void printShops(std::list<Shop> &shops) {
    std::list<Shop>::iterator sit;
    int shopIdx = 1;

    std::cout << "Shops:" << std::endl;

    for(sit = shops.begin(); sit != shops.end(); sit++) {
        std::cout << "\033[1m" << shopIdx << ". " << (*sit).getName() << "\033[0m" << std::endl;
        shopIdx++;
    }

    std::cout << std::endl;
}

void enterShop(Player &player, Shop &shop) {
    bool isDone = false;
    char input;
    std::string itemName;
    Item selectedItem("NO_ITEM", 0, 0);

    while(!isDone) {
        shop.printShop();
        player.printInventory();

        std::cout << "Would you like to (B)uy or (S)ell? Q to quit: ";
        std::cin >> input;
        std::cin.ignore(64, '\n');
        std::cin.clear();

        if (input == 'Q' || input == 'q') {
            std::cout << "\n\033[1;34mCome back soon!\033[0m\n\n";
            return;
        };

        if (input == 'B' || input == 'b') {
            // buy
            std::cout << "Enter the item you wish to buy: ";
            std::getline(std::cin, itemName);

            if (shop.canAffordItem(itemName, player.getMoney())) {
                if (shop.purchaseItem(itemName, selectedItem)) {
                    player.setMoney(player.getMoney() - selectedItem.getPristineValue());
                    shop.setMoney(shop.getMoney() + selectedItem.getPristineValue());
                    player.addItem(selectedItem);
                } else {
                    std::cout << "That is an invalid item!" << std::endl;
                    getchar();
                }
            } else {
                std::cout << "You can't afford that!" << std::endl;
                getchar();
            }


        } else if (input == 'S' || input == 's') {
            // sell
            std::cout << "Enter the item you wish to sell: ";
            std::getline(std::cin, itemName);

            if (player.canAffordItem(itemName, shop.getMoney())) {
                if (player.removeItem(itemName, selectedItem)) {
                    shop.setMoney(shop.getMoney() - selectedItem.getUsedValue());
                    player.setMoney(player.getMoney() + selectedItem.getUsedValue());
                    shop.addItem(selectedItem);
                } else {
                    std::cout << "That is an invalid item!" << std::endl;
                    getchar();
                }
            } else {
                std::cout << "The merchant doesn't have enough money!" << std::endl;
                getchar();
            }
        } else {
            // quit
            isDone = true;
        }

        if (!isDone) std::cout << "\n\033[1;32mTransaction successful!\033[0m\n\n";
    }
}
