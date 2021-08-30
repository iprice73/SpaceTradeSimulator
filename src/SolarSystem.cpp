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

SolarSystem::SolarSystem(const std::shared_ptr<Time>& time)
    : time_(time) {
    bigBang(time);
    currPlanet_ = planets_[2];
}

void SolarSystem::bigBang(const std::shared_ptr<Time>& time) {
    for (const auto& planet : planetsData) {
        planets_.emplace_back(std::make_shared<Planet>(time,
                                                       planet.first,
                                                       planet.second,
                                                       (planet.first == "Jupyter") ? StoreClass::Advanced : StoreClass::Basic));
    }
}

void SolarSystem::travelAnimation(float time) {
    size_t travelTime{};
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
        travelTime = static_cast<size_t>(time * 1000.f);
        std::this_thread::sleep_for(std::chrono::milliseconds(travelTime));
    }
    std::cout << std::endl;
    orbit(travelTime);
}

std::shared_ptr<Planet> SolarSystem::getDestPlanet(size_t index) {
    if (index <= planets_.size() && index > 0) {
        return planets_[index - 1];
    }
    return nullptr;
}

float SolarSystem::calculateDistance(const std::shared_ptr<Planet>& planet) const {
    return static_cast<float>(sqrt(pow(planet->getX() - currPlanet_->getX(), 2) +
                                   pow((planet->getY() - currPlanet_->getY()), 2)));
}

int SolarSystem::calculatePrice(float dist, const std::unique_ptr<Ship>& ship) const {
    int costPerCrewMate = 10, fuelPrice = 0, crewPrice = 0;
    crewPrice = ship->getCrew() * costPerCrewMate;
    fuelPrice = static_cast<int>((dist * static_cast<float>(ship->getEngine()) /
                                  static_cast<float>(ship->getCrew())));

    return (ship->getEngine() == EngineClass::ImpropabilityDrive) ? crewPrice : fuelPrice + crewPrice;
}

void SolarSystem::travel(std::shared_ptr<Planet>& destPlanet, const std::unique_ptr<Player>& player) {
    float dist = calculateDistance(destPlanet);
    if (int price = calculatePrice(dist, player->getShip()); player->getMoney() > price) {
        currPlanet_.swap(destPlanet);
        *player -= price;
        float travelTime = dist / static_cast<float>(player->getShip()->getEngine());
        travelAnimation(travelTime);
        time_->notify(static_cast<int>(travelTime * 1000.f));
        currPlanet_->getStore()->preparePrices(player);
    } else {
        std::cout << "  \033[1;31m You don't have enough money.\033[0m\n";
    }
}

void SolarSystem::orbit(size_t days) {
    static double angle = 0.0;
    for (size_t i = 0; i < days; i++) {
        float slower = 1.0f;
        for (const auto& planet : planets_) {
            auto newX = static_cast<float>(planet->getDistance() * cos(angle / slower));
            auto newY = static_cast<float>(planet->getDistance() * sin(angle / slower));
            planet->setPos(newX, newY);
            slower *= 2.0f;
        }
        angle += M_PI / 50;
    }
}

void SolarSystem::printPlanets() const {
    size_t i = 1;
    for (const auto& el : planets_) {
        std::cout << i++ << ". " << el->getName();
        float dist = calculateDistance(el);
        if (dist == 0) {
            std::cout << "\033[1;32m <--- You are here\033[0m\n";
        } else if (dist > 0 && dist < 5) {
            std::cout << "  \033[1;32m " << dist << " AU\033[0m\n";
        } else if (dist >= 5 && dist < 15) {
            std::cout << "  \033[1;33m " << dist << " AU\033[0m\n";
        } else {
            std::cout << "  \033[1;31m " << dist << " AU\033[0m\n";
        }
    }
}
