#include <iostream>
#include <memory>

#include "Item.hpp"

int main() {

    std::shared_ptr<Cargo> ptr = std::make_unique<Item>("owoc", 10, 20, Rarity::legendary);
    
    std::cout << ptr->getPrice() << '\n';

    for (int i = 0; i < 10; i++) {
        std::cout << "siema\n";
    }


    return 0;
}
