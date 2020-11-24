#include <iostream>

#include "Store.hpp"
#include "Player.hpp"

int main() {
    Store store;
    store.showStore();
    Ship ship("dog", 42, EngineClass::Antygravity);

    Player player(1000, &ship);

    store.buy(3, 2, &player);
    std::cout << "------------------------\n";
    player.getShip()->show();
    std::cout << "------------------------\n";
    store.showStore();

    return 0;
}
