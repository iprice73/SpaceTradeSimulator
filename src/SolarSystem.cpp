#include "SolarSystem.hpp"

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

void SolarSystem::show() const {
    for (const auto& planet : map_) {
        std::cout << planet.getName() << ' ' << planet.getDistance() << '\n';
    }
}
