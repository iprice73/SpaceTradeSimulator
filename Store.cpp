#include "Store.hpp"

#include <algorithm>
#include <random>

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
    while (i < 4) {
        auto alcoIndex = getRand(0, 5);
        Alcohol alco(alcoNames[alcoIndex], getRand(10, 50), getRand(1, 5), alcoContent[alcoIndex]);
        if (std::none_of(stock_.begin(), stock_.end(), [&alco](const auto& ptr) { return ptr->getName() == alco.getName(); })) {
            stock_.emplace_back(std::make_unique<Alcohol>(alco));
        }
    }
}
