#pragma once

#include "Store.hpp"

class Planet {
private:
    std::string name_{};
    double AU_{};
    Store store_{};
    double posX_{};
    double posY_{};

public:
    Planet(const std::string& name = "Earth", double AU = 1.0, double posX = 1, double PosY = 1);
    std::string getName() const { return name_; }
    double getDistance() const { return AU_; }
    Store& getStore() { return store_; }

    void setPos(double x, double y);

    bool operator==(const Planet& newPlanet);
    bool operator!=(const Planet& newPlanet);

    double getX() const { return posX_; }
    double getY() const { return posY_; }
};
