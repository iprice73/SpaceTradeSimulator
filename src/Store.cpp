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

Response Store::purchaseCargo(size_t index, int amount, Player* player) {
    int price = amount * stock_[index]->getPrice();
    if (amount > stock_[index]->getAmount()) {
        return Response::LackOfCargo;
    }
    if (amount <= 0) {
        return Response::InvalidAmount;
    }
    if (price > player->getMoney()) {
        return Response::LackOfMoney;
    }
    if (amount > player->getShip()->getAvaiableSpace()) {
        return Response::LackOfSpace;
    }

    player->buy(makeNewCargo(stock_[index], amount));
    *player -= price;
    removeCargo(stock_[index], amount);

    return Response::Done;
}

Response Store::sellCargo(size_t index, int amount, Player* player) {
    auto cargo = player->sellCargo(index, amount);
    *player += cargo->getPrice() * amount;
    
    return Response::Done;
}

