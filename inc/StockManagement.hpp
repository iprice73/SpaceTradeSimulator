#pragma once

#include <iostream>
#include <memory>
#include <vector>

#include "Alcohol.hpp"
#include "Item.hpp"
#include "Spice.hpp"

enum class Response {
    Done,
    LackOfMoney,
    LackOfSpace,
    InvalidAmount,
    InvalidIndex
};

constexpr int maxAlcoAmount = 10, maxItemAmount = 10, maxSpiceAmount = 10;
class StockManagement {
protected:
    std::vector<std::unique_ptr<Cargo>> stock_{};

    void addCargo(std::unique_ptr<Cargo>&& cargo);
    void removeCargo(const std::unique_ptr<Cargo>& cargo, int amount);
    void setPricesBaseOnAmount();

    std::unique_ptr<Cargo> makeNewCargo(const std::unique_ptr<Cargo>& oldCargo, int amount) const;
    Response validation(size_t index, int amount, int money = -1, int space = -1) const;
    std::string handleRespone(Response re) const;

public:
    friend std::ostream& operator<<(std::ostream& out, const StockManagement& stock);
};
