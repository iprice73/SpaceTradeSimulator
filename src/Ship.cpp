#include "Ship.hpp"

#include <algorithm>

Ship::Ship(const std::string& name, int crewSize, EngineClass engine)
    : name_(name), crewSize_(crewSize), engine_(engine) {}

void Ship::load(std::unique_ptr<Cargo>&& cargo) {
    magazine_.emplace_back(std::move(cargo));
    std::cout << "SIEMA TU ŁADOWNIA\n";
}

void Ship::show() const {
    int i = 1;
    for (const auto& el : magazine_) {
        std::cout << i++ << " " << el->getName() << "   |   Amount: " << el->getAmount() << "   |   Price: " << el->getPrice() << "\n";
    }
}
