#include "Store.hpp"

#include <algorithm>
#include <random>

#include "Alcohol.hpp"
#include "Item.hpp"
#include "Spice.hpp"

constexpr int marketSection = 2;

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
    const std::vector<std::string> alcoNames{"Beer", "Vodka", "Rum", "Ale", "Absint", "Amarena"};
    const std::vector<double> alcoContent{7.5, 40.0, 50.0, 3.5, 75.0, 99.9};
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
    constexpr Rarity rarities[4] = {Rarity::common, Rarity::rare, Rarity::epic, Rarity::legendary};
    int i = 0;
    while (i < marketSection) {
        auto index = getRand(0, 3);
        Item item("alien", getRand(10, 25), getRand(1, 3), rarities[index]);
        if (std::none_of(stock_.begin(), stock_.end(), [&item](const auto& ptr) { return ptr->getBasePrice() == item.getBasePrice(); })) {
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

std::unique_ptr<Cargo> Store::makeCargoToBuy(const std::unique_ptr<Cargo>& oldCargo, int amount) {
    auto name = oldCargo->getName();
    auto basePrice = oldCargo->getBasePrice();

    if (typeid(*oldCargo) == typeid(Alcohol)) {
        Alcohol alco(name, basePrice, amount, 99.0);
        return std::make_unique<Alcohol>(alco);
    } else if (typeid(*oldCargo) == typeid(Item)) {
        Item item(name, basePrice, amount, Rarity::common);
        return std::make_unique<Item>(item);
    } else if (typeid(*oldCargo) == typeid(Spice)) {
        Spice spice(name, basePrice, amount, 10);
        return std::make_unique<Spice>(spice);
    }

    return nullptr;
}

void Store::removeFromStore(int index, int amount) {
    if (stock_[index]->getAmount() == amount) {
        stock_.erase(std::remove(stock_.begin(), stock_.end(), stock_[index]), stock_.end());
    } else {
        (*stock_[index]) -= amount;
    }
}

Response Store::buy(int index, int amount, Player* p) {
    index--;
    p->getShip()->load(makeCargoToBuy(stock_[index], amount));
    removeFromStore(index, amount);
    

    return Response::Done;
}

Response Store::sell() {
    return Response::Done;
}

void Store::showStore() const {
    int i = 1;
    for (const auto& el : stock_) {
        std::cout << i++ << " " << el->getName() << "   |   Amount: " << el->getAmount() << "   |   Price: " << el->getPrice() << "\n";
    }
}
