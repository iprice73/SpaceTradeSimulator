#include <iostream>

#include "Store.hpp"
#include "Player.hpp"

int main() {
    
    Ship ship;
    Player player(1000, &ship);
    Store store;
    int index, amount;

    

    while(player.getMoney() > 0) {
        system("clear");
        std::cout << store;
        std::cout << ship;
        std::cout << "Buy index, amount\n";
        std::cin >> index >> amount;
        store.purchaseCargo(index - 1, amount, &player);
//        system("clear");
        std::cout << store;
        std::cout << ship;
        std::cout << "Sell index, amount\n";
        std::cin >> index >> amount;
        store.sellCargo(index - 1, amount, &player);
  //      system("clear");
    }

    return 0;
}
