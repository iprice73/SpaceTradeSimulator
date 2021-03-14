#pragma once

#include "Planet.hpp"

class SolarSystem {
private:
    std::vector<std::shared_ptr<Planet>> planets_{};
    std::shared_ptr<Planet> currPlanet_{};

    void bigBang();
    float calculateDistance(const Planet* planet) const;
    int calculatePrice(float dist, Ship* ship) const;
    void travelAnimation(float time);

public:
    SolarSystem();

    std::shared_ptr<Planet> getCurrPlanet() { return currPlanet_; }
    std::shared_ptr<Planet> getDestPlanet(size_t index);

    void travel(std::shared_ptr<Planet>& destPlanet, Player* player);
    void orbit(size_t days);
    void printPlanets() const;
};
