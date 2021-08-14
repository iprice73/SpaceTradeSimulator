#include "Ship.hpp"

#include <algorithm>

Ship::Ship(const std::shared_ptr<Time>& time, const std::string& name, int crewSize, int avaiableSpace, EngineClass engine)
    : time_(time), name_(name), crewSize_(crewSize), avaiableSpace_(avaiableSpace), engine_(engine) {
    time_->addObserver(this);
}

Ship::~Ship() {
    time_->removeObserver(this);
}

void Ship::load(cargo_ptr&& cargo) {
    avaiableSpace_ -= cargo->getAmount();
    addCargo(std::move(cargo));
}

void Ship::unload(const cargo_ptr& cargo, int amount) {
    avaiableSpace_ += amount;
    removeCargo(cargo, amount);
}

void Ship::changePrice(const cargo_ptr& cargo) {
    int amount = cargo->getAmount();
    int price = cargo->getBasePrice();
    auto it = std::find_if(stock_.begin(), stock_.end(), [&cargo](const auto& el) { return *el == *cargo; });
    if (it != stock_.end()) {
        (*it)->setBasePrice(price - (price * amount / 30));
    }
    cargo->setBasePrice(price - (price * amount / 30));
}

cargo_ptr Ship::getCargo(size_t index, int amount) {
    auto re = validation(index, amount);
    cargo_ptr cargo{};
    if (re == Response::Done) {
        cargo = stock_[index]->clone(amount);
        unload(stock_[index], amount);
    }
    std::cout << handleResponse(re) << '\n';

    return cargo;
}

void Ship::nextDay(int days) {
    for (const auto& ptr : stock_) {
        ptr->nextDay(days);
    }
}
