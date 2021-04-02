#include "Ship.hpp"

#include <algorithm>

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

void Ship::changePrice(const std::unique_ptr<Cargo>& cargo) {
    if (auto it(std::find_if(stock_.begin(), stock_.end(),
                             [&cargo](const auto& ptr) {
                                 return cargo->getName() == ptr->getName();
                             }));
        it != stock_.end()) {
        (*it)->setPrice(cargo->getPrice());
    }
}

std::unique_ptr<Cargo> Ship::getCargo(size_t index, int amount) {
    auto re = validation(index, amount);
    std::unique_ptr<Cargo> cargo = nullptr;
    if (re == Response::Done) {
        cargo = makeNewCargo(stock_[index], amount);
        unload(stock_[index], amount);
    }
    std::cout << handleRespone(re) << '\n';

    return cargo;
}
