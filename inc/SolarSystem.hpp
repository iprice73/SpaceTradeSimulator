#pragma once

#include "Planet.hpp"

class SolarSystem {
private:
    std::vector<Planet> planets_{};
    Planet currPlanet_{};
    
    void bigBang();

public:
    SolarSystem();

    Planet* getCurrPlanet() { return &currPlanet_; }
    Planet* getDestPlanet(size_t index);

    bool travel(Planet* planet, Player* player);
    void orbit(size_t days);
    void show() const;

    friend std::ostream& operator<<(std::ostream& os, const SolarSystem& planets);
};
