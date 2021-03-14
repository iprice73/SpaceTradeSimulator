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
    if (auto existingCargoIt (std::find_if(stock_.begin(), stock_.end(),
                                            [&cargo](const auto& ptr) { return *ptr == *cargo; }));
        existingCargoIt == stock_.end()) {
        stock_.push_back(std::move(cargo));
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

Response StockManagement::validation(size_t index, int amount, int money, int space) const {
    if (index >= stock_.size()) {
        return Response::InvalidIndex;
    }
    if (amount <= 0 || amount > stock_[index]->getAmount()) {
        return Response::InvalidAmount;
    }
    if (space != -1 && amount > space) {
        return Response::LackOfSpace;
    }
    if (money != -1 && stock_[index]->getPrice() * amount > money) {
        return Response::LackOfMoney;
    }

    return Response::Done;
}

std::string StockManagement::handleRespone(Response re) const {
    switch (re) {
    case Response::InvalidIndex:
        return "\033[1;31mEnter proper index.\033[0m";
    case Response::InvalidAmount:
        return "\033[1;31mEnter proper amount.\033[0m";
    case Response::LackOfMoney:
        return "\033[1;31mYou don't have money for this.\033[0m";
    case Response::LackOfSpace:
        return "\033[1;31mYou don't have enough space.\033[0m";
    case Response::Done:
        return "\033[1;32mTransaction completed.\033[0m";
    default:
        return "How did you get there?";
    }
}

std::ostream& operator<<(std::ostream& out, const StockManagement& stock) {
    std::string horizontalSeparator(40, '=');
    int i = 0;

    out << horizontalSeparator
        << "\n"
        << "|| Cargo avaiable"
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
