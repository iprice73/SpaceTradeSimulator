#pragma once

#include "Planet.hpp"

class SolarSystem {
private:
    std::vector<Planet> planets_{};
    Planet* currPlanet_{};

    void bigBang();
    float calculateDistance(const Planet* planet) const;
    int calculatePrice(float dist, Ship* ship) const;
    void travelAnimation(float time) const;

public:
    SolarSystem();

    Planet* getCurrPlanet() { return currPlanet_; }
    Planet* getDestPlanet(size_t index);

    void travel(Planet* planet, Player* player);
    void orbit(size_t days);
    void printPlanets() const;
};
