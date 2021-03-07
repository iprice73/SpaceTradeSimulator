#include "SolarSystem.hpp"

#include <algorithm>
#include <chrono>
#include <cmath>
#include <thread>

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
    currPlanet_ = &planets_[2];
}

void SolarSystem::bigBang() {
    for (const auto& planet : planetsData) {
        planets_.emplace_back(planet.first, planet.second);
    }
}

void SolarSystem::travelAnimation(int time) const {
    float progress = 0.0f;
    while (progress < 1.0) {
        int barWidth = 50;
        std::cout << 'O';
        int pos = static_cast<int>(static_cast<float>(barWidth) * progress);
        for (int i = 0; i < barWidth; ++i) {
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
        std::this_thread::sleep_for(std::chrono::milliseconds(time));
    }
    std::cout << std::endl;
}

double SolarSystem::calculateDistance(const Planet* planet) const {
    return sqrt(pow(planet->getX() - currPlanet_->getX(), 2) + pow((planet->getY() - currPlanet_->getY()), 2));
}

Planet* SolarSystem::getDestPlanet(size_t index) {
    if (index <= planets_.size() && index > 0) {
        return &planets_[index - 1];
    }
    return nullptr;
}

void SolarSystem::travel(Planet* destPlanet, Player* player) {
    double dist = calculateDistance(destPlanet);
    int time = static_cast<int>((dist / static_cast<int>(player->getShip()->getEngine())) * 1000.0);
    int value = 20;
    if (player->getMoney() > 0) {  // this is a place holder
        currPlanet_ = destPlanet;
        *player -= value;
        travelAnimation(time);
    }
}

double angle = 0;

void SolarSystem::orbit(size_t days) {
    for (size_t i = 0; i < days; i++) {
        for (auto& planet : planets_) {
            double slower = 1.0;
            double newX = planet.getDistance() * cos(angle / slower);
            double newY = planet.getDistance() * sin(angle / slower);
            planet.setPos(newX, newY);
            slower += 10.0;
        }
        angle += M_PI / 50;
    }
}

void SolarSystem::printPlanets() const {
    size_t i = 1;
    for (const auto& el : planets_) {
        std::cout << i++ << ". " << el.getName();
        double dist = calculateDistance(&el);
        if (dist < 1) {
            std::cout << "  \033[1;32m " << dist << " AU\033[0m\n";
        } else if (dist > 1 && dist < 15) {
            std::cout << "  \033[1;33m " << dist << " AU\033[0m\n";
        } else {
            std::cout << "  \033[1;31m " << dist << " AU\033[0m\n";
        }
    }
}       
