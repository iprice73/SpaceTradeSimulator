#pragma once

#include "Ship.hpp"
class Player : public Observer {
private:
    std::shared_ptr<Time> m_time{};
    int m_money{};
    std::unique_ptr<Ship> m_ship{};

public:
    Player(const std::shared_ptr<Time>& time, int money);
    ~Player();

    int getMoney() const { return m_money; }
    int getSpace() const { return m_ship->getAvaiableSpace(); }
    std::unique_ptr<Ship>& getShip() { return m_ship; }


    void moveCargoToShip(std::unique_ptr<Cargo>&& cargo);
    std::unique_ptr<Cargo> getCargoFromShip(size_t index, int amount);
    void notifyAboutPrice(const cargo_vec& storeStock) const { m_ship->changePrice(storeStock); }

    void addMoney(int price);
    void subMoney(int price);

    // Override from Time
    void nextDay(int days) override { m_ship->nextDay(days); }
};
