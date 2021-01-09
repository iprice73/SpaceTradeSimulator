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
        map_.emplace_back(planet.first, planet.second);
    }
}

bool SolarSystem::travel(const Planet& dest) {
    (void)dest;
    return true;
}

double angle = 0;

void SolarSystem::orbit(size_t days) {
    for (size_t i = 0; i < days; i++) {
        for (auto& planet : map_) {
            short int slower = 1;
            auto newX = static_cast<double>(planet.getDistance() * cos(angle / slower));
            auto newY = static_cast<double>(planet.getDistance() * sin(angle / slower));
            planet.setPos(newX, newY);
            slower++;
        }
        angle += M_PI / 50;
    }
}

void SolarSystem::show() const {
    for (const auto& planet : map_) {
        std::cout << '(' << planet.getX() << ',' << planet.getY() << ")\n";
    }
}
