#pragma once

#include "Player.hpp"
#include "StockManagement.hpp"
#include "Time.hpp"

extern std::map<std::string, double> alcoData;

class Store : public StockManagement, public Observer {
private:
    std::shared_ptr<Time> m_time{};

    template <class cargoType, class dataContainer>
    void generateCargo(const dataContainer& data, int basePrice);

    void generateStore();
    void balancePricesBasedOnAmount();

public:
    Store(const std::shared_ptr<Time>& time);
    ~Store();

    static int getRand(int min, int max);
    void preparePrices(const std::unique_ptr<Player>& player) const;
    void purchaseCargo(size_t index, int amount, const std::unique_ptr<Player>& player);
    void sellCargo(size_t index, int amount, const std::unique_ptr<Player>& player);

    void nextDay(int days) override;
};
