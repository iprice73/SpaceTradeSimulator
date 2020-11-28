#include <iostream>

#include "Store.hpp"
#include "Player.hpp"

std::string handleRespone(Response re) {
    switch (re)
    {
    case Response::LackOfCargo:
        return "We don't have this mush in stock.";
    case Response::LackOfMoney:
        return "You don't have money for this.";
    case Response::LackOfSpace:
        return "You don't have enough space.";
    case Response::Done:
        return "Transaction completed.";
    default:
        return "How did you get there?";
    }
}

int main() {
    
    Ship ship;
    Player player(3000, &ship);
    Store store;
    int index, amount;

    

    while(player.getMoney() > 100) {
        std::cout << store;
        std::cout << "Index: " << " Amount: " << "      Your money: " << player.getMoney() << "    Avaiable space: " << ship.getAvaiableSpace() << '\n';
        std::cin >> index >> amount;
        auto re = store.purchaseCargo(index - 1, amount, &player);
        std ::cout << handleRespone(re) << '\n';
        std::cout << ship;
        std::cout << store;
        std::cout << "Index: " << " Amount: " << "      Your money: " << player.getMoney() << "    Avaiable space: " << ship.getAvaiableSpace() << '\n';
        std::cin >> index >> amount;
        auto ry = store.sellCargo(index - 1, amount, &player);
        std::cout << ship;
        std::cout << handleRespone(ry) << '\n';
    }

    return 0;
}
