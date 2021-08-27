#pragma once

#include <map>

#include "Ship.hpp"
#include "Player.hpp"

enum class StoreClass {
    None = 0,
    Basic = 1,
    Advanced = 2
};

class SpaceCraftStore {
public:
    SpaceCraftStore(StoreClass storeClass);

    void buyEngine(const std::unique_ptr<Player>& player);
    void buyShip(const std::unique_ptr<Player>& player);
    void printShips() const;

private:
    void parseShipFromFile(const std::string& path);
    void loadFromFile(const std::string& category);
    void generateShips();

    StoreClass m_class{StoreClass::None};
    std::map<std::unique_ptr<Ship>, int> m_ships{};
    std::vector<EngineClass> m_engines{};
};
