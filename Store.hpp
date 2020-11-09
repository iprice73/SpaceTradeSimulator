#pragma once

#include <memory>
#include <vector>

#include "Alcohol.hpp"
#include "Item.hpp"
#include "Spice.hpp"

const std::vector<std::string> alcoNames {
    "Beer",
    "Vodka",
    "Rum",
    "Ale",
    "Absint",
    "Amarena"
};

const std::vector<double> alcoContent {
    7.5,
    40.0,
    40.0,
    3.5,
    75.0,
    99.9
};

class Store {
private:
    std::vector<std::unique_ptr<Cargo>> stock_{};


    int getRand(int min, int max) const;

    void generateAlcos();
    void generateItems();
    void generateEngineParts();

public:
    Store();

    
};
