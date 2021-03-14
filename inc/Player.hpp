#pragma once

#include "Ship.hpp"

class Player {
private:
    int money_ = 100;
    std::unique_ptr<Ship> ship_;

public:
    Player(int money);

    int getMoney() const { return money_; }
    int getSpace() const { return ship_->getAvaiableSpace(); }
    Ship* getShip() const { return ship_.get(); }


    void buy(std::unique_ptr<Cargo>&& cargo);
    std::unique_ptr<Cargo> sellCargo(size_t index, int amount);

    Player& operator+=(int price);
    Player& operator-=(int price);
};
