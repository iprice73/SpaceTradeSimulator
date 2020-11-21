#include "Item.hpp"

Item::Item(const std::string& name, int basePrice, int amount, Rarity rarity)
    : Cargo(name, basePrice, amount), rarity_(rarity) {}

int Item::getPrice() const {
    return basePrice_ * static_cast<int>(rarity_);
}
