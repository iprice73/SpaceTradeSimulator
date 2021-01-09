#include "SolarSystem.hpp"

#include <cmath>

const std::vector<std::pair<std::string, double>> planets{
    {"Mercury", 0.39},
    {"Venus", 0.723},
    {"Earth", 1.0},
    {"Mars", 1.524},
    {"Jupyter", 5.203},
    {"Saturn", 9.539},
    {"Uranus", 19.18},
    {"Neptune", 30.06}};

SolarSystem::SolarSystem() {
    bigBang();
}

void SolarSystem::bigBang() {
    for (const auto& planet : planets) {
        map_.emplace_back(planet.first, planet.second, 1, 1);
    }
}

bool SolarSystem::travel(const Planet& dest) {
    if (currPlanet_ == dest) {
        return false;
    }
    currPlanet_ = dest;
    return true;
}

double angle = 0;

void SolarSystem::orbit(size_t days) {
    for (size_t i = 0; i < days; i++) {
        for (auto& planet : map_) {
            auto newX = static_cast<double>(planet.getDistance() * cos(angle));
            auto newY = static_cast<double>(planet.getDistance() * sin(angle));
            planet.setPos(newX, newY);
        }
        angle += M_PI / 50;
    }
}

void SolarSystem::show() const {
    for (const auto& planet : map_) {
        std::cout << planet.getName() << ' ' << planet.getDistance() << '\n';
    }
}
