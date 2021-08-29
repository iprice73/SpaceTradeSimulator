#include "Store.hpp"

#include <algorithm>
#include <iomanip>
#include <random>

constexpr int marketSection = 4;
constexpr int cargoTypes = 3;

std::map<std::string, double> alcoData{
    {"Amarena", 0.9},
    {"Ale", 3.5},
    {"Beer", 6.5},
    {"Rum", 30.0},
    {"Vodka", 40},
    {"Absint", 74.0}};

std::map<std::string, Rarity> itemData{
    {"Xenomorph", Rarity::legendary},
    {"Tea", Rarity::common},
    {"Cocaine", Rarity::rare},
    {"Death star", Rarity::epic},
    {"Stuff", Rarity::common},
    {"Dark matter", Rarity::epic}};

std::map<std::string, int> spiceData{
    {"Red", 10},
    {"Yellow", 20},
    {"Black", 30},
    {"Magenta", 40},
    {"Cyan", 50},
    {"Orange", 60}};

Store::Store(const std::shared_ptr<Time>& time)
    : time_(time) {
    m_stock.reserve(marketSection * cargoTypes);
    generateStore();
    time_->addObserver(this);
}

Store::~Store() {
    time_->removeObserver(this);
}

void Store::preparePrices(const std::unique_ptr<Player>& player) const {
    player->notifyAboutPrice(m_stock);
}

int Store::getRand(int min, int max) {
    std::random_device device;
    std::mt19937 gen(device());
    std::uniform_int_distribution<int> distirb(min, max);

    return distirb(gen);
}

template <class cargoType, class dataContainer>
void Store::generateCargo(const dataContainer& data, int basePrice) {
    size_t i = 0;
    while (i < marketSection) {
        auto it = std::next(data.begin(), getRand(0, static_cast<int>(data.size()) - 1));
        cargoType cargo(it->first, basePrice, getRand(1, 30), it->second);
        if (std::none_of(m_stock.begin(), m_stock.end(), [&cargo](const auto& ptr) { return *ptr == cargo; })) {
            m_stock.push_back(std::make_unique<cargoType>(cargo));
            i++;
        }
    }
}

void Store::balancePricesBasedOnAmount() {
    for (const auto& cargo : m_stock) {
        cargo->setBasePrice(cargo->getBasePrice() - (cargo->getBasePrice() * cargo->getAmount() / 31));  // 1 above max amount
    }
}

void Store::generateStore() {
    m_stock.clear();
    generateCargo<Alcohol>(alcoData, 10);  // BaseAlcoPrice
    generateCargo<Item>(itemData, 50);     // BaseItemPrice
    generateCargo<Spice>(spiceData, 100);  // BaseSpicePrice
    balancePricesBasedOnAmount();
}

void Store::purchaseCargo(size_t index, int amount, const std::unique_ptr<Player>& player) {
    auto re = validation(index, amount, player->getMoney(), player->getSpace());
    if (re == Response::Done) {
        int price = amount * m_stock[index]->getPrice();
        player->buy(m_stock[index]->clone(amount));
        *player -= price;
        removeCargo(m_stock[index], amount);
    }
    std::cout << handleResponse(re) << '\n';
}

void Store::sellCargo(size_t index, int amount, const std::unique_ptr<Player>& player) {
    if (auto cargo = player->sellCargo(index, amount); cargo) {
        *player += cargo->getPrice() * amount;
        addCargo(std::move(cargo));
    }
}

void Store::nextDay([[maybe_unused]] int days) {
    generateStore();
    
}
