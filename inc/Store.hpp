#pragma once

#include "Player.hpp"
#include "StockManagement.hpp"

class Store : public StockManagement {
private:

    void generateAlcos();
    void generateItems();
    void generateSpices();


public:
    Store();
    
    static int getRand(int min, int max);
    void purchaseCargo(size_t index, int amount, const std::unique_ptr<Player>& player);
    void sellCargo(size_t index, int amount, const std::unique_ptr<Player>& player);
    void preparePrices(const std::unique_ptr<Player>& player);
};
