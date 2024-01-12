#include "Ship.hpp"

#include <algorithm>

constexpr int PRICE_MULTIPLIER = 2;

Ship::Ship(const std::string& name, int crewSize, int avaiableSpace, EngineClass engine)
    : name_(name), crewSize_(crewSize), avaiableSpace_(avaiableSpace), engine_(engine) {
}

int Ship::calculateAvaiableSpace(int newSpace) const {
    for (const auto& cargo : m_stock) {
        newSpace -= cargo->getAmount();
    }
    return newSpace;
}

void Ship::setSpace(int newSpace) {
    avaiableSpace_ = calculateAvaiableSpace(newSpace);
}

void Ship::load(cargo_ptr&& cargo) {
    avaiableSpace_ -= cargo->getAmount();
    addCargo(std::move(cargo));
}

void Ship::unload(const cargo_ptr& cargo, int amount) {
    avaiableSpace_ += amount;
    subtractCargo(cargo, amount);
}

void Ship::changePrice(const cargo_vec& cargoStock) {
    for (const auto& shipCargo : m_stock) {
        auto pred = [&shipCargo](const auto& cargo){ return *shipCargo == *cargo; };
        auto it = std::ranges::find_if(cargoStock, pred);
        int price = (it != cargoStock.end()) ? (*it)->getBasePrice() : shipCargo->getBasePrice() * PRICE_MULTIPLIER;
        shipCargo->setBasePrice(price);
    }
}

std::optional<cargo_ptr> Ship::getCargo(size_t index, int amount) {
    auto re = validation(index, amount);
    if (re == Response::Done) {
        cargo_ptr cargo = m_stock[index]->clone(amount);
        unload(m_stock[index], amount);
        std::cout << "\033[1;32mTransaction completed.\033[0m";
        return cargo;
    }

    return std::nullopt;
}

void Ship::nextDay(int days) {
    for (const auto& ptr : m_stock) {
        ptr->nextDay(days);
    }
}
