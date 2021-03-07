#pragma once

#include "Planet.hpp"

class SolarSystem {
private:
    std::vector<Planet> planets_{};
    Planet* currPlanet_{};

    void bigBang();
    double calculateDistance(const Planet* planet) const;
    void travelAnimation(int time) const;

public:
    SolarSystem();

    Planet* getCurrPlanet() { return currPlanet_; }
    Planet* getDestPlanet(size_t index);

    void travel(Planet* planet, Player* player);
    void orbit(size_t days);
    void printPlanets() const;
};
