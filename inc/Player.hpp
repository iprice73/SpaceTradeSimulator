#pragma once

#include "Ship.hpp"
class Player : public Observer {
private:
    std::shared_ptr<Time> time_{};
    int money_{};
    std::unique_ptr<Ship> ship_{};

public:
    Player(const std::shared_ptr<Time>& time, int money);
    ~Player();

    int getMoney() const { return money_; }
    int getSpace() const { return ship_->getAvaiableSpace(); }
    std::unique_ptr<Ship>& getShip() { return ship_; }


    void buy(std::unique_ptr<Cargo>&& cargo);
    std::unique_ptr<Cargo> sellCargo(size_t index, int amount);
    void notifyAboutPrice(const cargo_vec& storeStock) const { ship_->changePrice(storeStock); }

    void addMoney(int price);
    void subMoney(int price);

    // Override from Time
    void nextDay(int days) override { ship_->nextDay(days); }
};
