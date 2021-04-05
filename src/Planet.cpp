#include "Planet.hpp"

Planet::Planet(const std::shared_ptr<Time>& time, const std::string& name, double AU, double posX, double posY)
    : name_(name), AU_(AU), posX_(posX), posY_(posY), store_(std::make_unique<Store>(time)) {}

void Planet::setPos(double x, double y) {
    posX_ = x;
    posY_ = y;
}

bool Planet::operator==(const Planet& newPlanet) {
    return name_ == newPlanet.name_;
}

bool Planet::operator!=(const Planet& newPlanet) {
    return name_ != newPlanet.name_;
}

