#include <iostream>
#include <memory>

#include "Item.hpp"
#include "Spice.hpp"

int main() {

    std::shared_ptr<Cargo> ptr = std::make_unique<Item>("owoc", 10, 20, Rarity::legendary);
    Spice spice("orange", 1000, 2, 0.75);
    
    std::cout << ptr->getPrice() << '\n';
    ptr = std::make_unique<Spice>(spice);

    std::cout << ptr->getPrice() << '\n';

    for (int i = 0; i < 10; i++) {
        std::cout << "siema\n";
    }


    return 0;
}
