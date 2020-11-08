#pragma once

#include "Cargo.hpp"

constexpr double bestPurity = 1.00;

class Spice : public Cargo {
private:
    double purity_{};

public:
    Spice(const std::string& name, int basePrice, int amount, double purity);
    ~Spice() {}

    int getPrice() const override;

};
