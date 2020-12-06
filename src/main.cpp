#include <iostream>

#include "Player.hpp"
#include "Store.hpp"
#include "Planet.hpp"

int main() {
    // Ship ship;
    // Player player(1000, &ship);
    // Store store;
    // int index, amount;

    // while (player.getMoney() > 0) {
    //     system("clear");
    //     std::cout << store;
    //     std::cout << ship;
    //     std::cout << "Buy index, amount\n";
    //     std::cin >> index >> amount;
    //     store.purchaseCargo(index - 1, amount, &player);
    //     //        system("clear");
    //     std::cout << store;
    //     std::cout << ship;
    //     std::cout << "Sell index, amount\n";
    //     std::cin >> index >> amount;
    //     store.sellCargo(index - 1, amount, &player);
    //     //      system("clear");
    // }

    Planet planet("Mercury", 0.39, 1, 1);
    std::cout << planet.getName() << '\n';
    std::cout << planet.getStore() << '\n';

    return 0;
}
