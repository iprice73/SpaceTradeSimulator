#include "Planet.hpp"

Planet::Planet(const std::string& name, double AU, int posX, int posY)
    : name_(name), AU_(AU), posX_(posX), posY_(posY) {}

bool Planet::operator==(const Planet& newPlanet) {
    return name_ == newPlanet.name_;
}
