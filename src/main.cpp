#include <iostream>

#include "Store.hpp"
#include "Player.hpp"

int main() {
    
    Ship ship;
    Player player(3000, &ship);
    Store store;
    int index, amount;

    

    while(player.getMoney() > 100) {
        std::cout << store;
        std::cout << "Index: " << " Amount: " << "      Your money: " << player.getMoney() << "    Avaiable space: " << ship.getAvaiableSpace() << '\n';
        std::cin >> index >> amount;
        store.purchaseCargo(index - 1, amount, &player);
        std::cout << ship;
        // std::cout << store;
        // std::cout << "Index: " << " Amount: " << "      Your money: " << player.getMoney() << "    Avaiable space: " << ship.getAvaiableSpace() << '\n';
        // std::cin >> index >> amount;
        // store.sellCargo(index - 1, amount, &player);
        // std::cout << ship;
    }

    return 0;
}
