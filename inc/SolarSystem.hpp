#pragma once

#include "Planet.hpp"
#include "Time.hpp"

class SolarSystem {
private:
    std::shared_ptr<Time> m_time{};
    std::vector<std::shared_ptr<Planet>> m_planets{};
    std::shared_ptr<Planet> m_currPlanet{};

    void bigBang(const std::shared_ptr<Time>& time);
    float calculateDistance(const std::shared_ptr<Planet>& planet) const;
    int calculatePrice(float dist, const std::unique_ptr<Ship>& ship) const;
    void travelAnimation(float time);

public:
    SolarSystem(const std::shared_ptr<Time>& time);

    std::shared_ptr<Planet> getCurrPlanet() { return m_currPlanet; }
    std::shared_ptr<Planet> getDestPlanet(size_t index);

    const std::unique_ptr<Store>& getCurrPlanetStrore() const { return m_currPlanet->getStore(); };
    const cargo_vec& getStockFromCurrPlanet() const { return m_currPlanet->getStock(); };

    void purchaseCargoFromCurrPlanet(size_t index, int amount, const std::unique_ptr<Player>& player);
    void travel(std::shared_ptr<Planet>& destPlanet, const std::unique_ptr<Player>& player);
    void orbit(size_t days);
    void printPlanets() const;
};
