#pragma once

#include "Planet.hpp"

class SolarSystem {
private:
    std::vector<Planet> map_{};
    void bigBang();

public:
    SolarSystem();

    void show() const;
};
