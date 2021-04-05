#pragma once

#include "Planet.hpp"
#include "Time.hpp"

class SolarSystem {
private:
    std::shared_ptr<Time> time_{};
    std::vector<std::shared_ptr<Planet>> planets_{};
    std::shared_ptr<Planet> currPlanet_{};

    void bigBang(const std::shared_ptr<Time>& time);
    float calculateDistance(const std::shared_ptr<Planet>& planet) const;
    int calculatePrice(float dist, const std::unique_ptr<Ship>& ship) const;
    void travelAnimation(float time);

public:
    SolarSystem(const std::shared_ptr<Time>& time);

    std::shared_ptr<Planet> getCurrPlanet() { return currPlanet_; }
    std::shared_ptr<Planet> getDestPlanet(size_t index);

    void travel(std::shared_ptr<Planet>& destPlanet, const std::unique_ptr<Player>& player);
    void orbit(size_t days);
    void printPlanets() const;
};
