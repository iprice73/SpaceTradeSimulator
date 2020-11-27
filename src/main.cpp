#include <iostream>

#include "Store.hpp"
#include "Player.hpp"

std::string handleRespone(Response re) {
    switch (re)
    {
    case Response::InvalidIndex:
        return "There is no product with such number.";
    case Response::LackOfCargo:
        return "We don't have this mush in stock.";
    case Response::LackOfMoney:
        return "You don't have money for this.";
    case Response::Done:
        return "Transaction completed.";
    default:
        return "How did you get there?";
    }
}

int main() {
    
    Ship ship;
    Player player(1000, &ship);
    Store store;
    int index, amount;

    while(player.getMoney() > 100) {
    std::cout << store;
    std::cout << "Index: " << " Amount: " << "      Your money: " << player.getMoney() << '\n';
    std::cin >> index >> amount;
    auto re = store.purchase(index - 1, amount, &player);
    std ::cout << handleRespone(re) << '\n';
    std::cout << ship;
    }

    return 0;
}
