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

class StockManagement {
protected:
    std::vector<std::unique_ptr<Cargo>> stock_{};

    void addCargo(std::unique_ptr<Cargo>&& cargo);
    void removeCargo(const std::unique_ptr<Cargo>& cargo, int amount);

    std::unique_ptr<Cargo> makeNewCargo(const std::unique_ptr<Cargo>& oldCargo, int amount) const;
    Response validation(size_t index, int amount, int money, int space) const;
    std::string handleRespone(Response re) const;

public:
    friend std::ostream& operator<<(std::ostream& out, const StockManagement& stock);
};
