#pragma once

#include "Ship.hpp"

class Player {
private:
    int money_ = 0;
    Ship* ship_;

public:
    Player(int money, Ship* ship);
};
