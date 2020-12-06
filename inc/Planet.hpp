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
    Planet(const std::string& name, double AU, int posX, int PosY);
    std::string getName() const { return name_; }
    const Store& getStore() const { return store_; }
};
