#include "Store.hpp"

#include <algorithm>
#include <iomanip>
#include <random>

constexpr int marketSection = 4;

Store::Store() {
    constexpr int cargoTypes = 3;
    stock_.reserve(marketSection * cargoTypes);
    generateAlcos();
    generateItems();
    generateSpices();
    stock_.shrink_to_fit();
}

int Store::getRand(int min, int max) const {
    std::random_device device;
    std::mt19937 gen(device());
    std::uniform_int_distribution<int> distirb(min, max);

    return distirb(gen);
}

void Store::generateAlcos() {
    const std::vector<std::string> alcoNames{"Beer", "Vodka", "Rum", "Ale", "Absint", "Amarena"};
    const std::vector<double> alcoContent{7.5, 40.0, 50.0, 3.5, 75.0, 99.9};
    size_t i = 0;
    while (i < marketSection) {
        size_t index = getRand(0, 5);
        Alcohol alco(alcoNames[index], getRand(10, 50), getRand(1, 5), alcoContent[index]);
        if (std::none_of(stock_.begin(), stock_.end(), [&alco](const auto& ptr) { return *ptr == alco; })) {
            stock_.emplace_back(std::make_unique<Alcohol>(alco));
            i++;
        }
    }
}

void Store::generateItems() {
    constexpr Rarity rarities[4] = {Rarity::common, Rarity::rare, Rarity::epic, Rarity::legendary};
    const std::vector<std::string> spiceNames{"xenomorph", "tea", "cocaine", "death star", "stuff", "dark matter"};
    size_t i = 0;
    while (i < marketSection) {
        size_t index = getRand(0, 3);
        Item item(spiceNames[index], getRand(10, 25), getRand(1, 3), rarities[index]);
        if (std::none_of(stock_.begin(), stock_.end(), [&item](const auto& ptr) { return *ptr == item; })) {
            stock_.emplace_back(std::make_unique<Item>(item));
            i++;
        }
    }
}

void Store::generateSpices() {
    const std::vector<std::string> spiceNames{"red", "yellow", "black", "magenta", "cyan", "orange"};
    size_t i = 0;
    while (i < marketSection) {
        size_t index = getRand(0, 5);
        Spice spice(spiceNames[index], getRand(250, 300), getRand(2, 20), getRand(5, 100));
        if (std::none_of(stock_.begin(), stock_.end(), [&spice](const auto& ptr) { return *ptr == spice; })) {
            stock_.emplace_back(std::make_unique<Spice>(spice));
            i++;
        }
    }
}

std::unique_ptr<Cargo> Store::makeCargoToBuy(const std::unique_ptr<Cargo>& oldCargo, int amount) {
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

void Store::removeFromStore(const std::unique_ptr<Cargo>& cargo, int amount) {
    if (cargo->getAmount() == amount) {
        stock_.erase(std::remove(stock_.begin(), stock_.end(), cargo), stock_.end());
    } else {
        *cargo -= amount;
    }
}

Response Store::purchaseCargo(size_t index, int amount, Player* player) {
    int price = amount * stock_[index]->getPrice();
    if (amount > stock_[index]->getAmount()) {
        return Response::LackOfCargo;
    } else if (price > player->getMoney()) {
        return Response::LackOfMoney;
    } else if (amount > player->getShip()->getAvaiableSpace()) {
        return Response::LackOfSpace;
    }
    player->buy(makeCargoToBuy(stock_[index], amount));
    *player -= price;
    removeFromStore(stock_[index], amount);

    return Response::Done;
}

Response Store::sellCargo(size_t index, int amount, Player* player) {
    auto cargo = player->sellCargo(index, amount);
    *player += cargo->getPrice() * amount;
    
    return Response::Done;
}

std::ostream& operator<<(std::ostream& out, const Store& store) {
    std::string horizontalSeparator(40, '=');
    int i = 0;

    out << horizontalSeparator
        << "\n"
        << "|| Store's stock"
        << std::setw(14) << "| QTY "
        << "| PRICE "
        << "||\n"
        << horizontalSeparator << "\n";

    for (const auto& el : store.stock_) {
        out << "|| "
            << std::setw(2) << ++i << ". "
            << std::setw(17) << std::left << el->getName();

        out << std::setw(4) << "|" << std::left << el->getAmount() << " | "
            << std::setw(5) << std::right << el->getPrice() << " ||\n";
    }
    out << horizontalSeparator << "\n";

    return out;
}
