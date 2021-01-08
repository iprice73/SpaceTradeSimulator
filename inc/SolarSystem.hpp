#pragma once

#include "Planet.hpp"

class SolarSystem {
private:
    std::vector<Planet> map_{};
    Planet currPlanet_{};
    void bigBang();

public:
    SolarSystem();

    bool travel(const Planet& dest);
    void orbit(int days);
    void show() const;
};
