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

void Ship::unload(const std::unique_ptr<Cargo>& cargo, int amount) {
    if (amount == cargo->getAmount()) {
        stock_.erase(std::remove(stock_.begin(), stock_.end(), cargo), stock_.end());
    } else {
        *cargo -= amount;
    }
    avaiableSpace_ += amount;
}

std::unique_ptr<Cargo> Ship::getCargo(size_t index, int amount) {
    auto cargo =  StockManagement::makeNewCargo(stock_[index], amount);
    unload(stock_[index], amount);

    return cargo;
}

std::ostream& operator<<(std::ostream& out, const Ship& ship) {
    std::string horizontalSeparator(40, '*');
    int i = 0;

    out << horizontalSeparator
        << "\n"
        << "|| Ship's magazine"
        << std::setw(12) << "| QTY "
        << "| PRICE "
        << "||\n"
        << horizontalSeparator << "\n";

    for (const auto& el : ship.stock_) {
        out << "|| "
            << std::setw(2) << ++i << ". "
            << std::setw(17) << std::left << el->getName();

        out << std::setw(4) << "|" << std::left << el->getAmount() << " | "
            << std::setw(5) << std::right << el->getPrice() << " ||\n";
    }
    out << horizontalSeparator << "\n";

    return out;
}
