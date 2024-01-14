#pragma once

#include "Docks.hpp"
#include "Store.hpp"
#include "Time.hpp"

class Planet {
private:
    std::string m_name{};
    double m_AU{};
    std::unique_ptr<SpaceCraftStore> m_spaceStore{};
    double m_posX{};
    double m_posY{};
    std::unique_ptr<Store> m_store{};

public:
    Planet(const std::shared_ptr<Time>& time,
           const std::string& name = "Earth",
           double AU = 1.0,
           StoreClass storeclass = StoreClass::Basic,
           double posX = 1,
           double PosY = 1);

    std::string getName() const { return m_name; }
    double getDistance() const { return m_AU; }
    std::unique_ptr<Store>& getStore() { return m_store; }
    const cargo_vec& getStock() { return m_store->getStock(); }
    std::unique_ptr<SpaceCraftStore>& getSpaceStore() { return m_spaceStore; }

    double getX() const { return m_posX; }
    double getY() const { return m_posY; }

    void setPos(double x, double y);

    bool operator==(const Planet& newPlanet);
    bool operator!=(const Planet& newPlanet);
};
