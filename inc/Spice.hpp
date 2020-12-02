#pragma once

#include "ICargo.hpp"

constexpr int bestPurity = 100;

class Spice : public Cargo {
private:
    int purity_{};

public:
    Spice(const std::string& name, int basePrice, int amount, int purity);

    int getPrice() const override;

    Spice& operator--();

};
