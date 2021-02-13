#include "SolarSystem.hpp"

#include <algorithm>
#include <cmath>

const std::vector<std::pair<std::string, double>> planetsData{
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
    for (const auto& planet : planetsData) {
        planets_.emplace_back(planet.first, planet.second);
    }
}

double SolarSystem::calculateDistance(Planet* planet) const {
    return sqrt(pow(planet->getX() - currPlanet_.getX(), 2) + pow((planet->getY() - currPlanet_.getY()), 2));
}

Planet* SolarSystem::getDestPlanet(size_t index) {
    if (index <= planets_.size() && index > 0) {
        return &planets_[index - 1];
    }
    return nullptr;
}

bool SolarSystem::travel(Planet* destPlanet, Player* player) {
    double dist = calculateDistance(destPlanet);
    double time = dist / static_cast<int>(player->getShip()->getEngine());
    std::cout << time << '\n';
    int value = 20;
    if (player->getMoney() > 100) {
        currPlanet_ = std::move(*destPlanet);
        *player -= value;
        return true;
    }
    return false;
}

double angle = 0;

void SolarSystem::orbit(size_t days) {
    for (size_t i = 0; i < days; i++) {
        for (auto& planet : planets_) {
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
    for (const auto& planet : planets_) {
        std::cout << '(' << planet.getX() << ',' << planet.getY() << ")\n";
    }
}

std::ostream& operator<<(std::ostream& os, const SolarSystem& planets) {
    size_t i = 1;
    for (const auto& el : planets.planets_) {
        os << i++ << ". " << el.getName() << '\n';
    }
    return os;
}
