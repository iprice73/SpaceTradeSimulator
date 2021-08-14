#include "Item.hpp"

Item::Item(const std::string& name, int basePrice, int amount, Rarity rarity)
    : Cargo(name, basePrice, amount), rarity_(rarity) {}

void Item::setRarity(Rarity rarity) {
    rarity_ = rarity;
}

int Item::getPrice() const {
    return basePrice_ *  static_cast<int>(rarity_);
}

cargo_ptr Item::clone(int amount) const {
    return std::make_unique<Item>(name_, basePrice_, amount, rarity_);
}

void Item::nextDay([[maybe_unused]]int days) {
    // static int lifeSpan = 0;
    // lifeSpan += days;
    // Rarity rare = Rarity::common;
    // if (lifeSpan >= 40 && lifeSpan < 60) {
    //     rare = Rarity::rare;
    // } else if (lifeSpan >= 60 && lifeSpan < 100) {
    //     rare = Rarity::epic;
    // } else if (lifeSpan >= 100) {
    //     rare = Rarity::legendary;
    // }
    // setRarity(rare);
}
