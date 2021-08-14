#include "Store.hpp"

#include <algorithm>
#include <iomanip>
#include <random>

constexpr int marketSection = 4;
constexpr int cargoTypes = 3;

std::map<std::string, double> alcoData {
    {"Beer", 6.5},
    {"Vodka", 40},
    {"Rum", 30.0},
    {"Ale", 3.5},
    {"Absint", 74.0},
    {"Amarena", 0.9}
};

std::map<std::string, int> spiceData {
    {"Red", 10},
    {"Yellow", 20},
    {"Black", 30},
    {"Magenta", 40},
    {"Cyan", 50},
    {"Orange", 60}
};

Store::Store(const std::shared_ptr<Time>& time)
    : time_(time) {
    stock_.reserve(marketSection * cargoTypes);
    generateCargos();
    setPricesBaseOnAmount();
    time_->addObserver(this);
}

Store::~Store() {
    time_->removeObserver(this);
}

void Store::preparePrices(const std::unique_ptr<Player>& player) {
    for (const auto& ptr : stock_) {
        player->notifyAboutPrice(ptr);
    }
}

int Store::getRand(int min, int max) {
    std::random_device device;
    std::mt19937 gen(device());
    std::uniform_int_distribution<int> distirb(min, max);

    return distirb(gen);
}

void Store::generateAlcos() {
    size_t i = 0;
    while (i < marketSection) {
        auto item = alcoData.begin();
        std::advance(item, getRand(0, static_cast<int>(alcoData.size()) - 1));
        Alcohol alco(item->first, baseAlcoPrice_, getRand(1, 30), item->second);
        if (std::none_of(stock_.begin(), stock_.end(), [&alco](const auto& ptr) { return *ptr == alco; })) {
            stock_.emplace_back(std::make_unique<Alcohol>(alco));
            i++;
        }
    }
}

void Store::generateItems() {
    const std::vector<std::string> itemNames{"xenomorph", "tea", "cocaine", "death star", "stuff", "dark matter"};
    size_t i = 0;
    while (i < marketSection) {
        Item item(itemNames[getRand(0, 3)], getRand(10, 25), getRand(1, 10), Rarity::common);
        if (std::none_of(stock_.begin(), stock_.end(), [&item](const auto& ptr) { return *ptr == item; })) {
            stock_.emplace_back(std::make_unique<Item>(item));
            i++;
        }
    }
}

void Store::generateSpices() {
    size_t i = 0;
    while (i < marketSection) {
        auto item = spiceData.begin();
        std::advance(item, getRand(0, static_cast<int>(spiceData.size()) - 1));
        Spice spice(item->first, getRand(250, 300), getRand(1, 10), item->second);
        if (std::none_of(stock_.begin(), stock_.end(), [&spice](const auto& ptr) { return *ptr == spice; })) {
            stock_.emplace_back(std::make_unique<Spice>(spice));
            i++;
        }
    }
}

void Store::generateCargos() {
    stock_.clear();
    generateAlcos();
    generateItems();
    generateSpices();
}

void Store::purchaseCargo(size_t index, int amount, const std::unique_ptr<Player>& player) {
    auto re = validation(index, amount, player->getMoney(), player->getSpace());
    if (re == Response::Done) {
        int price = amount * stock_[index]->getPrice();
        player->buy(stock_[index]->clone(amount));
        *player -= price;
        removeCargo(stock_[index], amount);
    }
    std::cout << handleRespone(re) << '\n';
}

void Store::sellCargo(size_t index, int amount, const std::unique_ptr<Player>& player) {
    if (auto cargo = player->sellCargo(index, amount); cargo) {
        *player += cargo->getPrice() * amount;
        addCargo(std::move(cargo));
    }
}

void Store::nextDay([[maybe_unused]] int days) {
    generateCargos();
}
