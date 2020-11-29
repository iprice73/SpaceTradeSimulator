#include "Ship.hpp"

#include <algorithm>
#include <iomanip>

Ship::Ship(const std::string& name, int crewSize, int avaiableSpace, EngineClass engine)
    : name_(name), crewSize_(crewSize), avaiableSpace_(avaiableSpace), engine_(engine) {}

void Ship::load(std::unique_ptr<Cargo>&& cargo) {
    int amount = cargo->getAmount();
    auto existingCargoIt = std::find_if(stock_.begin(), stock_.end(), [&cargo](const auto& ptr) { return *ptr == *cargo; });
    if (existingCargoIt == stock_.end()) {
        stock_.emplace_back(std::move(cargo));
    } else {
        **existingCargoIt += amount;
    }
    avaiableSpace_ -= amount;
}

std::unique_ptr<Cargo> Ship::getCargo(size_t index, int amount) {
    auto cargo =  makeNewCargo(stock_[index], amount);
    removeCargo(stock_[index], amount);

    return cargo;
}
