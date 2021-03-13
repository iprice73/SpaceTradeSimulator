#include "SolarSystem.hpp"

#include <algorithm>
#include <chrono>
#include <cmath>
#include <thread>

const std::vector<std::pair<std::string, float>> planetsData{
    {"Mercury", 0.39f},
    {"Venus", 0.723f},
    {"Earth", 1.0f},
    {"Mars", 1.524f},
    {"Jupyter", 5.203f},
    {"Saturn", 9.539f},
    {"Uranus", 19.18f},
    {"Neptune", 30.06f}};

SolarSystem::SolarSystem() {
    bigBang();
    currPlanet_ = &planets_[2];
}

void SolarSystem::bigBang() {
    for (const auto& planet : planetsData) {
        planets_.emplace_back(planet.first, planet.second);
    }
}

void SolarSystem::travelAnimation(float time) const {
    float progress = 0.0f;
    while (progress < 1.0) {
        size_t barWidth = 50;
        std::cout << 'O';
        size_t pos = static_cast<size_t>(static_cast<float>(barWidth) * progress);
        for (size_t i = 0; i < barWidth; ++i) {
            if (i < pos) {
                std::cout << '=';
            } else if (i == pos) {
                std::cout << '>';
            } else {
                std::cout << ' ';
            }
        }
        std::cout << 'o' << '\r';
        std::cout.flush();
        progress += 0.02f;
        int newTime = static_cast<int>(time * 1000.f);
        std::this_thread::sleep_for(std::chrono::milliseconds(newTime));
    }
    std::cout << std::endl;
}

Planet* SolarSystem::getDestPlanet(size_t index) {
    if (index <= planets_.size() && index > 0) {
        return &planets_[index - 1];
    }
    return nullptr;
}

float SolarSystem::calculateDistance(const Planet* planet) const {
    return static_cast<float>(sqrt(pow(planet->getX() - currPlanet_->getX(), 2) +
                                   pow((planet->getY() - currPlanet_->getY()), 2)));
}

int SolarSystem::calculatePrice(float dist, Ship* ship) const {
    int costPerCrewMate = 10, fuelPrice = 0, crewPrice = 0;
    crewPrice = ship->getCrew() * costPerCrewMate;
    fuelPrice = static_cast<int>((dist * static_cast<float>(ship->getEngine()) /
                                  static_cast<float>(ship->getCrew())));

    return (ship->getEngine() == EngineClass::ImpropabilityDrive) ? crewPrice : fuelPrice + crewPrice;
}

void SolarSystem::travel(Planet* destPlanet, Player* player) {
    float dist{}, time{};
    dist = calculateDistance(destPlanet);
    time = dist / static_cast<float>(player->getShip()->getEngine());
    int price = calculatePrice(dist, player->getShip());

    if (player->getMoney() > 0) {
        currPlanet_ = destPlanet;
        *player -= price;
        travelAnimation(time);
    }
}

double angle = 0.0;

void SolarSystem::orbit(size_t days) {
    for (size_t i = 0; i < days; i++) {
        for (auto& planet : planets_) {
            float slower = 1.0f, newX, newY;
            newX = static_cast<float>(planet.getDistance() * cos(angle / slower));
            newY = static_cast<float>(planet.getDistance() * sin(angle / slower));
            planet.setPos(newX, newY);
            slower += 10.0f;
        }
        angle += M_PI / 50;
    }
}

void SolarSystem::printPlanets() const {
    size_t i = 1;
    for (const auto& el : planets_) {
        std::cout << i++ << ". " << el.getName();
        float dist = calculateDistance(&el);
        if (dist == 0) {
            std::cout << "\033[1;32m <--- You are here\033[0m\n";
        } else if (dist < 1 && dist > 0) {
            std::cout << "  \033[1;32m " << dist << " AU\033[0m\n";
        } else if (dist > 1 && dist < 15) {
            std::cout << "  \033[1;33m " << dist << " AU\033[0m\n";
        } else {
            std::cout << "  \033[1;31m " << dist << " AU\033[0m\n";
        }
    }
}
