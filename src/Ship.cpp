#include "Ship.hpp"

#include <algorithm>

Ship::Ship(const std::string& name, int crewSize, EngineClass engine)
    : name_(name), crewSize_(crewSize), engine_(engine) {}

void Ship::load(std::unique_ptr<Cargo>& cargo) {
    magazine_.emplace_back(std::move(cargo));
}

void Ship::unload(const std::unique_ptr<Cargo>& cargo) {
    magazine_.erase(std::remove(magazine_.begin(), magazine_.end(), cargo), magazine_.end());
}
