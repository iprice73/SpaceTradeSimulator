#include <iostream>

#include "Player.hpp"
#include "Store.hpp"
#include "Planet.hpp"

int main() {
    Ship ship;
    Player player(1000, &ship);
    int index, amount;

    Planet planet("Mercury", 0.39, 1, 1);
    std::cout << planet.getName() << '\n';

    while (player.getMoney() > 0) {
        system("clear");
        std::cout << planet.getStore();
        std::cout << ship;
        std::cout << "Buy index, amount\n";
        std::cin >> index >> amount;
        planet.getStore().purchaseCargo(index - 1, amount, &player);
        //        system("clear");
        std::cout << planet.getStore();
        std::cout << ship;
        std::cout << "Sell index, amount\n";
        std::cin >> index >> amount;
        planet.getStore().sellCargo(index - 1, amount, &player);
        //      system("clear");
    }

    

    return 0;
}
