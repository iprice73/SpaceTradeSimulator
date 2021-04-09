#pragma once

#include "ICargo.hpp"

enum class Rarity {
    common = 1,
    rare = 2,
    epic = 4,
    legendary = 8
};

class Item : public Cargo {
private:
    Rarity rarity_{};

public:
    Item(const std::string& name, int basePrice, int amount, Rarity rarity);

    void setRarity(Rarity rarity);

    // Override from Cargo
    int getPrice() const override;

    // Override from Time
    void nextDay(int days) override;
};
