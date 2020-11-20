#include "Store.hpp"

#include <algorithm>
#include <random>

constexpr int marketSection = 4;

Store::Store() { 
    generateAlcos();
}

int Store::getRand(int min, int max) const {
    std::random_device device;
    std::mt19937 gen(device());
    std::uniform_int_distribution<int> distirb(min, max);

    return distirb(gen);
}

void Store::generateAlcos() {
    int i = 0;
    while (i < marketSection) {
        auto alcoIndex = getRand(0, 5);
        Alcohol alco(alcoNames[alcoIndex], getRand(10, 50), getRand(1, 5), alcoContent[alcoIndex]);
        if (std::none_of(stock_.begin(), stock_.end(), [&alco](const auto& ptr) { return ptr->getName() == alco.getName(); })) {
            stock_.emplace_back(std::make_unique<Alcohol>(alco));
            i++;
        }
    }
}

void Store::generateSpices() {
    int i = 0;
    while (i < marketSection) {
        auto spiceIndex = getRand(0, 5);
        
        if (std::none_of(stock_.begin(), stock_.end(), [](const auto& ptr) { return ptr->getName() == alco.getName(); })) {
            stock_.emplace_back(std::make_unique<Spice>(alco));
            i++;
        }
    }
}

void Store::showStore() const {
    for (const auto& el :stock_) {
        std::cout << "Name: " << el->getName() << "   |   Amount: " << el->getAmount() << "   |   Price: " << el->getPrice() << "\n";
    }
}
