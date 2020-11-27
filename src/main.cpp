#include <iostream>

#include "Store.hpp"
#include "Player.hpp"

int main() {
    Store store;
    store.showStore();
    Ship ship("dog", 42, EngineClass::Antygravity);

    Player player(1000, &ship);
    std::cout << "MONEY: " << player.getMoney() << '\n';
    int index = 6;
    store.buy(index, 2, &player);
    std::cout << "------------------------\n";
    player.getShip()->show();
    std::cout << "------------------------\n";
    store.showStore();
    std::cout << "MONEY: " << player.getMoney() << '\n';

    return 0;
}
