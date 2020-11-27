#include "Ship.hpp"

#include <algorithm>
#include <iomanip>

Ship::Ship(const std::string& name, int crewSize, EngineClass engine)
    : name_(name), crewSize_(crewSize), engine_(engine) {}

void Ship::load(std::unique_ptr<Cargo>&& cargo) {
    auto existingCargoIt = std::find_if(magazine_.begin(), magazine_.end(), [&cargo](const auto& ptr) { return *ptr == *cargo; });
    if (existingCargoIt == magazine_.end()) {
        magazine_.emplace_back(std::move(cargo));
    } else {
        **existingCargoIt += cargo->getAmount();
    }
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
