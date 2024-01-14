#include "Planet.hpp"

Planet::Planet(const std::shared_ptr<Time>& time,
               const std::string& name,
               double AU,
               StoreClass storeClass,
               double posX,
               double posY)
    : m_name(name),
      m_AU(AU),
      m_spaceStore(std::make_unique<SpaceCraftStore>(storeClass)),
      m_posX(posX),
      m_posY(posY),
      m_store(std::make_unique<Store>(time)) {}

void Planet::setPos(double x, double y) {
    m_posX = x;
    m_posY = y;
}

bool Planet::operator==(const Planet& newPlanet) {
    return m_name == newPlanet.m_name;
}

bool Planet::operator!=(const Planet& newPlanet) {
    return m_name != newPlanet.m_name;
}
