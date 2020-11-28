#include "Ship.hpp"

#include <algorithm>
#include <iomanip>

Ship::Ship(const std::string& name, int crewSize, int avaiableSpace, EngineClass engine)
    : name_(name), crewSize_(crewSize), avaiableSpace_(avaiableSpace), engine_(engine) {}

std::unique_ptr<Cargo> Ship::makeCargoToBuy(const std::unique_ptr<Cargo>& oldCargo, int amount) {
    std::string name = oldCargo->getName();
    int basePrice = oldCargo->getBasePrice();
    int price = oldCargo->getPrice();

    if (typeid(*oldCargo) == typeid(Alcohol)) {
        Alcohol alco(name, basePrice, amount, price * spiritus / basePrice);
        return std::make_unique<Alcohol>(alco);
    } else if (typeid(*oldCargo) == typeid(Item)) {
        Item item(name, basePrice, amount, static_cast<Rarity>(price / basePrice));
        return std::make_unique<Item>(item);
    } else if (typeid(*oldCargo) == typeid(Spice)) {
        Spice spice(name, basePrice, amount, price * bestPurity / basePrice);
        return std::make_unique<Spice>(spice);
    }

    return nullptr;
}

void Ship::load(std::unique_ptr<Cargo>&& cargo) {
    int amount = cargo->getAmount();
    auto existingCargoIt = std::find_if(magazine_.begin(), magazine_.end(), [&cargo](const auto& ptr) { return *ptr == *cargo; });
    if (existingCargoIt == magazine_.end()) {
        magazine_.emplace_back(std::move(cargo));
    } else {
        **existingCargoIt += amount;
    }
    avaiableSpace_ -= amount;
}

void Ship::unload(const std::unique_ptr<Cargo>& cargo, int amount) {
    if (amount == cargo->getAmount()) {
        magazine_.erase(std::remove(magazine_.begin(), magazine_.end(), cargo), magazine_.end());
    } else {
        *cargo -= amount;
    }
    avaiableSpace_ += amount;
}

std::unique_ptr<Cargo> Ship::getCargo(size_t index, int amount) {
    auto cargo =  makeCargoToBuy(magazine_[index], amount);
    unload(magazine_[index], amount);

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

    for (const auto& el : ship.magazine_) {
        out << "|| "
            << std::setw(2) << ++i << ". "
            << std::setw(17) << std::left << el->getName();

        out << std::setw(4) << "|" << std::left << el->getAmount() << " | "
            << std::setw(5) << std::right << el->getPrice() << " ||\n";
    }
    out << horizontalSeparator << "\n";

    return out;
}
