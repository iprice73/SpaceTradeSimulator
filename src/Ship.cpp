#include "Ship.hpp"

#include <algorithm>

Ship::Ship(const std::string& name, int crewSize, EngineClass engine)
    : name_(name), crewSize_(crewSize), engine_(engine) {}
