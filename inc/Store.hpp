#pragma once

#include "Player.hpp"
#include "StockManagement.hpp"

enum class Response {
    Done,
    LackOfCargo,
    LackOfMoney,
    LackOfSpace,
    InvalidAmount
};

class Store : public StockManagement {
private:
    int getRand(int min, int max) const;

    void generateAlcos();
    void generateItems();
    void generateSpices();
    void removeFromStore(const std::unique_ptr<Cargo>& cargo, int amount);
   
public:
    Store();
    Response purchaseCargo(size_t index, int amount, Player* player);
    Response sellCargo(size_t index, int amount, Player* player);
    friend std::ostream& operator<<(std::ostream& out, const Store& store);
};
