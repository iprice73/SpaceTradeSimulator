#include "Store.hpp"

#include <algorithm>
#include <random>

constexpr int marketSection = 4;

Store::Store() {
    generateAlcos();
    generateItems();
    generateSpices();
}

int Store::getRand(int min, int max) const {
    std::random_device device;
    std::mt19937 gen(device());
    std::uniform_int_distribution<int> distirb(min, max);

    return distirb(gen);
}

void Store::generateAlcos() {
    const std::vector<std::string> alcoNames {"Beer", "Vodka", "Rum", "Ale", "Absint", "Amarena"};
    const std::vector<double> alcoContent { 7.5, 40.0, 50.0, 3.5, 75.0, 99.9};
    int i = 0;
    while (i < marketSection) {
        auto index = getRand(0, 5);
        Alcohol alco(alcoNames[index], getRand(10, 50), getRand(1, 5), alcoContent[index]);
        if (std::none_of(stock_.begin(), stock_.end(), [&alco](const auto& ptr) { return ptr->getName() == alco.getName(); })) {
            stock_.emplace_back(std::make_unique<Alcohol>(alco));
            i++;
        }
    }
}

void Store::generateItems() {
    constexpr Rarity rarities[4] = { Rarity::common, Rarity::rare, Rarity::epic, Rarity::legendary }; 
    int i = 0;
    while (i < marketSection) {
        auto index = getRand(0, 3);
        Item item("alien", getRand(10, 25), getRand(1, 3), rarities[index]);
        if (std::none_of(stock_.begin(), stock_.end(), [&item](const auto& ptr) { return ptr->getBasePrice() == item.getBasePrice(); } )) {
            stock_.emplace_back(std::make_unique<Item>(item));
            i++;
        }
    }
}

void Store::generateSpices() {
    const std::vector<std::string> spiceNames{"red", "yellow", "black", "magenta", "cyan", "orange"};
    int i = 0;
    while (i < marketSection) {
        auto index = getRand(0, 5);
        Spice spice(spiceNames[index], getRand(250, 300), getRand(2, 20), getRand(5, 100));
        if (std::none_of(stock_.begin(), stock_.end(), [&spice](const auto& ptr) { return ptr->getName() == spice.getName(); })) {
            stock_.emplace_back(std::make_unique<Spice>(spice));
            i++;
        }
    }
}

void Store::showStore() const {
    for (const auto& el : stock_) {
        std::cout << el->getName() << "   |   Amount: " << el->getAmount() << "   |   Price: " << el->getPrice() << "\n";
    }
}
