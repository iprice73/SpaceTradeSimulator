#pragma once

#include "Player.hpp"
#include "StockManagement.hpp"
#include "Time.hpp"

class Store : public StockManagement, public Observer {
private:
    std::shared_ptr<Time> time_;

    void generateAlcos();
    void generateItems();
    void generateSpices();
    void generateCargos();

public:
    Store(const std::shared_ptr<Time>& time);
    ~Store();

    static int getRand(int min, int max);
    void purchaseCargo(size_t index, int amount, const std::unique_ptr<Player>& player);
    void preparePrices(const std::unique_ptr<Player>& player);
    void sellCargo(size_t index, int amount, const std::unique_ptr<Player>& player);

    void nextDay(int days) override;
};
