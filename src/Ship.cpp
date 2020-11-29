#include "Ship.hpp"

#include <algorithm>
#include <iomanip>

Ship::Ship(const std::string& name, int crewSize, int avaiableSpace, EngineClass engine)
    : name_(name), crewSize_(crewSize), avaiableSpace_(avaiableSpace), engine_(engine) {}

void Ship::load(std::unique_ptr<Cargo>&& cargo) {
    avaiableSpace_ -= cargo->getAmount();
    addCargo(std::move(cargo));
}

void Ship::unload(const std::unique_ptr<Cargo>& cargo, int amount) {
    avaiableSpace_ += amount;
    removeCargo(cargo, amount);
}

std::unique_ptr<Cargo> Ship::getCargo(size_t index, int amount) {
    auto cargo = makeNewCargo(stock_[index], amount);
    unload(stock_[index], amount);

    return cargo;
}
