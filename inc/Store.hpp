#pragma once

#include "Player.hpp"
#include "StockManagement.hpp"
#include "Time.hpp"

extern std::map<std::string, double> alcoData;
extern std::map<std::string, int> spiceData;
class Store : public StockManagement, public Observer {
private:
    std::shared_ptr<Time> time_;
    const int baseAlcoPrice_{10};
    const int baseItemPrice_{20};
    const int baseSpicePrice_{30};

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
