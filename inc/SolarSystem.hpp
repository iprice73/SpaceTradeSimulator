#pragma once

#include "Planet.hpp"

class SolarSystem {
private:
    std::vector<Planet> map_{};
    Planet currPlanet_{};
    void bigBang();

public:
    SolarSystem();

    Planet& getCurrPlanet() { return currPlanet_; }

    bool travel(const Planet& dest);
    void orbit(size_t days);
    void show() const;
};
