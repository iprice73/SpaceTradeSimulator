#include "Spice.hpp"

Spice::Spice(const std::string& name, int basePrice, int amount, double purity)
    : Cargo(name, basePrice, amount), purity_(purity) {}

int Spice::getPrice() const {
    return basePrice_ * purity_ / bestPurity;
}
