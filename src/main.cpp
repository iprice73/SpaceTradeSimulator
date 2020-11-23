#include <iostream>

#include "Store.hpp"
#include "Player.hpp"

int main() {
    Ship ship("dog", 12, EngineClass::Antygravity);
    std::cout << ship.getName() << '\n';

    return 0;
}
