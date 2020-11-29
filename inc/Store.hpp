#pragma once

#include "Player.hpp"
#include "StockManagement.hpp"

class Store : public StockManagement {
private:
    int getRand(int min, int max) const;

    void generateAlcos();
    void generateItems();
    void generateSpices();

public:
    Store();
    void purchaseCargo(size_t index, int amount, Player* player);
    void sellCargo(size_t index, int amount, Player* player);
};
