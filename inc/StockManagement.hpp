#pragma once

#include <memory>
#include <string>
#include <vector>

#include "Alcohol.hpp"
#include "Item.hpp"
#include "Spice.hpp"

class StockManagement {
protected:
    std::vector<std::unique_ptr<Cargo>> stock_{};
    
    std::unique_ptr<Cargo> makeNewCargo(const std::unique_ptr<Cargo>& oldCargo, int amount);
    void removeCargo(const std::unique_ptr<Cargo>& cargo, int amount);
public:

    friend std::ostream& operator<<(std::ostream& out, const StockManagement& stock);
};
