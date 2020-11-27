#include <iostream>

#include "Store.hpp"
#include "Player.hpp"

int main() {
    
    Ship ship;
    Player player(1000, &ship);
    Store store;
    int index, amount;

    while(1) {
    std::cout << store;
    std::cout << "Index: " << " Amount: ";
    std::cin >> index >> amount;
    store.buy(index, amount, &player);
    std::cout << ship;
    }

    return 0;
}
