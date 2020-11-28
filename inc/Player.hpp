#pragma once

#include "Ship.hpp"

class Player {
private:
    int money_ = 100;
    Ship* ship_;

public:
    Player(int money, Ship* ship);

    int getMoney() const { return money_; }
    Ship* getShip() const { return ship_; }

    void buy(std::unique_ptr<Cargo>&& cargo);
    std::unique_ptr<Cargo> sellCargo(size_t index, int amount);

    Player& operator+=(int price);
    Player& operator-=(int price);
};
