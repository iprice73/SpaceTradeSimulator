#include "StockManagement.hpp"

std::unique_ptr<Cargo> StockManagement::makeNewCargo(const std::unique_ptr<Cargo>& oldCargo, int amount) {
    std::string name = oldCargo->getName();
    int basePrice = oldCargo->getBasePrice();
    int price = oldCargo->getPrice();

    if (typeid(*oldCargo) == typeid(Alcohol)) {
        Alcohol alco(name, basePrice, amount, price * spiritus / basePrice);
        return std::make_unique<Alcohol>(alco);
    } else if (typeid(*oldCargo) == typeid(Item)) {
        Item item(name, basePrice, amount, static_cast<Rarity>(price / basePrice));
        return std::make_unique<Item>(item);
    } else if (typeid(*oldCargo) == typeid(Spice)) {
        Spice spice(name, basePrice, amount, price * bestPurity / basePrice);
        return std::make_unique<Spice>(spice);
    }

    return nullptr;
}
