#include "Engine.hpp"

Engine::Engine(const std::string& name, int basePrice, int amount)
    : Cargo(name, basePrice, amount) {}

int Engine::getPrice() const { return basePrice_; }
