#include "StockManagement.hpp"

#include <algorithm>
#include <iomanip>

std::unique_ptr<Cargo> StockManagement::makeNewCargo(const std::unique_ptr<Cargo>& oldCargo, int amount) const {
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

void StockManagement::addCargo(std::unique_ptr<Cargo>&& cargo) {
    int amount = cargo->getAmount();
    auto existingCargoIt = std::find_if(stock_.begin(), stock_.end(), [&cargo](const auto& ptr) { return *ptr == *cargo; });
    if (existingCargoIt == stock_.end()) {
        stock_.emplace_back(std::move(cargo));
    } else {
        **existingCargoIt += amount;
    }
}

void StockManagement::removeCargo(const std::unique_ptr<Cargo>& cargo, int amount) {
    if (cargo->getAmount() == amount) {
        stock_.erase(std::remove(stock_.begin(), stock_.end(), cargo), stock_.end());
    } else {
        *cargo -= amount;
    }
}

std::ostream& operator<<(std::ostream& out, const StockManagement& stock) {
    std::string horizontalSeparator(40, '=');
    int i = 0;

    out << horizontalSeparator
        << "\n"
        << "|| Store's stock"
        << std::setw(14) << "| QTY "
        << "| PRICE "
        << "||\n"
        << horizontalSeparator << "\n";

    for (const auto& el : stock.stock_) {
        out << "|| "
            << std::setw(2) << ++i << ". "
            << std::setw(17) << std::left << el->getName();

        out << std::setw(4) << "|" << std::left << el->getAmount() << " | "
            << std::setw(5) << std::right << el->getPrice() << " ||\n";
    }
    out << horizontalSeparator << "\n";

    return out;
}
