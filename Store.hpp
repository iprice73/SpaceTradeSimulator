#pragma once

#include <memory>
#include <vector>

#include "Alcohol.hpp"
#include "Item.hpp"
#include "Spice.hpp"

class Store {
private:
    std::vector<std::unique_ptr<Cargo>> stock_{};

    int getRand(int min, int max) const;

    void generateAlcos();
    void generateItems();
    void generateSpices();

public:
    Store();
    void showStore() const;
    
};
