#include "Ship.hpp"

#include <algorithm>

Ship::Ship(const std::string& name, int crewSize, int avaiableSpace, EngineClass engine)
    : name_(name), crewSize_(crewSize), avaiableSpace_(avaiableSpace), engine_(engine) {
}

void Ship::load(cargo_ptr&& cargo) {
    avaiableSpace_ -= cargo->getAmount();
    addCargo(std::move(cargo));
}

void Ship::unload(const cargo_ptr& cargo, int amount) {
    avaiableSpace_ += amount;
    removeCargo(cargo, amount);
}

void Ship::changePrice(const cargo_vec& cargoStock) {
    for (const auto& shipCargo : m_stock) {
        auto it = std::find_if(cargoStock.begin(), cargoStock.end(), [&shipCargo](const auto& cargo) { return *shipCargo == *cargo; });
        int price = (it != cargoStock.end()) ? (*it)->getBasePrice() : shipCargo->getBasePrice() * 2;
        shipCargo->setBasePrice(price);
    }
}

cargo_ptr Ship::getCargo(size_t index, int amount) {
    auto re = validation(index, amount);
    cargo_ptr cargo{};
    if (re == Response::Done) {
        cargo = m_stock[index]->clone(amount);
        unload(m_stock[index], amount);
    }
    std::cout << handleResponse(re) << '\n';

    return cargo;
}

void Ship::nextDay(int days) {
    for (const auto& ptr : m_stock) {
        ptr->nextDay(days);
    }
}
