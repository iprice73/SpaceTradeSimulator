#pragma once

#include "Store.hpp"

class Planet {
private:
    std::string name_{};
    double AU_{};
    int posX_{};
    int posY_{};
    Store store_{};

public:
    Planet(const std::string& name = "Earth", double AU = 1.0, int posX = 1, int PosY = 1);
    std::string getName() const { return name_; }
    double getDistance() const { return AU_; }
    Store& getStore() { return store_; }
    bool operator==(const Planet& newPlanet);
};
