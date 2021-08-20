#pragma once

#include <map>

#include "Ship.hpp"
#include "Player.hpp"

class SpaceCraftStore {
public:
    SpaceCraftStore();

    void buyEngine(const std::unique_ptr<Player>& player);
    void buyShip(const std::unique_ptr<Player>& player);
    void printShips() const;

private:
    void parseShipFromFile(const std::string& path);
    void loadFromFile();
    void generateShips();

    std::map<std::unique_ptr<Ship>, int> m_ships{};
    std::vector<EngineClass> m_engines{};
};
