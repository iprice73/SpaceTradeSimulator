#include "Spice.hpp"

Spice::Spice(const std::string& name, int basePrice, int amount, int purity)
    : Cargo(name, basePrice, amount), purity_(purity) {
}

int Spice::getPrice() const {
    return basePrice_ * purity_;
}

cargo_ptr Spice::clone(int amount) const {
    return std::make_unique<Spice>(name_, basePrice_, amount, purity_);
}

Spice& Spice::operator--() {
    purity_ > 0 ? purity_-- : basePrice_ = 0;

    return *this;
}

void Spice::nextDay([[maybe_unused]] int days) {
    // for (int i = 0; i < days; i++) {
    //     this->operator--();
    // }
}
