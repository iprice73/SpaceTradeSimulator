#pragma once

#include <iostream>
#include <map>
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
    InvalidIndex,
    EmptyStore,
    SameCargo
};

class StockManagement {
protected:
    std::vector<std::unique_ptr<Cargo>> m_stock{};

    void addCargo(std::unique_ptr<Cargo>&& cargo);
    void removeCargo(const std::unique_ptr<Cargo>& cargo, int amount);

    Response validation(size_t index, int amount, int money = -1, int space = -1) const;
    std::string handleResponse(Response re) const;

public:
    friend std::ostream& operator<<(std::ostream& out, const StockManagement& stock);
};
