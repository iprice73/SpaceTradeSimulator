#include "Spice.hpp"

Spice::Spice(const std::string& name, int basePrice, int amount, int purity)
    : Cargo(name, basePrice, amount), purity_(purity) {}

int Spice::getPrice() const {
    return static_cast<int>(basePrice_ * purity_ / bestPurity);
}

Spice& Spice::operator--() {
    purity_--;
    return *this;
}
