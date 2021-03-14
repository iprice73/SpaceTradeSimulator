#pragma once

#include "Planet.hpp"

class SolarSystem {
private:
    std::vector<std::shared_ptr<Planet>> planets_{};
    std::shared_ptr<Planet> currPlanet_{};

    void bigBang();
    float calculateDistance(const std::shared_ptr<Planet>& planet) const;
    int calculatePrice(float dist, const std::unique_ptr<Ship>& ship) const;
    void travelAnimation(float time);

public:
    SolarSystem();

    std::shared_ptr<Planet> getCurrPlanet() { return currPlanet_; }
    std::shared_ptr<Planet> getDestPlanet(size_t index);

    void travel(std::shared_ptr<Planet>& destPlanet, const std::unique_ptr<Player>& player);
    void orbit(size_t days);
    void printPlanets() const;
};
