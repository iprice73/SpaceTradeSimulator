#pragma once

#include "ICargo.hpp"

enum class Rarity {
    common = 1,
    rare = 5,
    epic = 15,
    legendary = 25
};

class Item : public Cargo {
private:
    Rarity rarity_{};

public:
    Item(const std::string& name, int basePrice, int amount, Rarity rarity);

    int getPrice() const override;
};
