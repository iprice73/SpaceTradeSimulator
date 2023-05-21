#pragma once

#include <iostream>
#include <map>
#include <memory>
#include <vector>

#include "Alcohol.hpp"
#include "Item.hpp"
#include "Spice.hpp"
#include "Validator.hpp"

class StockManagement {
    private:
    std::vector<std::shared_ptr<IValidator>> setupValidators() const;
    void setupChain(const std::vector<std::shared_ptr<IValidator>>& validators) const;
protected:
    std::vector<std::unique_ptr<Cargo>> m_stock{};

    void addCargo(std::unique_ptr<Cargo>&& cargo);
    void subtractCargo(const std::unique_ptr<Cargo>& cargo, int amount);
    void removeIfNoCargo(const std::unique_ptr<Cargo>& cargo);

    Response validation(size_t index, int amount, int money = -1, int space = -1) const;
    std::string handleResponse(Response re) const;

public:
    friend std::ostream& operator<<(std::ostream& out, const StockManagement& stock);
};
