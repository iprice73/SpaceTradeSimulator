#pragma once

#include "Ship.hpp"

class Player {
private:
    int money_ = 0;
    Ship* ship_;

public:
    Player(int money, Ship* ship);

    int getMoney() const { return money_; }
    Ship* getShip() const { return ship_; }
};
