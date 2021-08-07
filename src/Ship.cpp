#include "Ship.hpp"

#include <algorithm>

Ship::Ship(const std::shared_ptr<Time>& time, const std::string& name, int crewSize, int avaiableSpace, EngineClass engine)
    : time_(time), name_(name), crewSize_(crewSize), avaiableSpace_(avaiableSpace), engine_(engine) {
        time_->addObserver(this);
    }

Ship::~Ship() {
    time_->removeObserver(this);
}

void Ship::load(std::unique_ptr<Cargo>&& cargo) {
    avaiableSpace_ -= cargo->getAmount();
    addCargo(std::move(cargo));
}

void Ship::unload(const std::unique_ptr<Cargo>& cargo, int amount) {
    avaiableSpace_ += amount;
    removeCargo(cargo, amount);
}

void Ship::changePrice([[maybe_unused]] const std::unique_ptr<Cargo>& cargo) {
    // TODO
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

void Ship::nextDay(int days) {
    for (const auto& ptr : stock_) {
        ptr->nextDay(days);
    }
}
