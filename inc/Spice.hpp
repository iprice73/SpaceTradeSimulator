#pragma once

#include "ICargo.hpp"
class Spice : public Cargo {
private:
    int purity_{};

public:
    Spice(const std::string& name, int basePrice, int amount, int purity);
    Spice& operator--();

    // Override from Cargo
    int getPrice() const override;
    cargo_ptr clone(int amount) const override;

    // Override form Time
    void nextDay(int days) override;

};
