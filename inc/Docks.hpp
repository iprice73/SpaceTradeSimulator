#pragma once

#include <map>

#include "Ship.hpp"
#include "Player.hpp"

enum class StoreClass {
    None,
    Basic,
    Advanced
};

class SpaceCraftStore {
public:
    SpaceCraftStore(StoreClass storeClass);

    void buyShip(const std::unique_ptr<Player>& player, size_t index);
    void buyEngine(const std::unique_ptr<Player>& player);
    void printShips() const;

private:
    auto getShip(size_t index) const;
    void editShip(const std::unique_ptr<Player>& player, const std::unique_ptr<Ship>& newShip) const;
    void parseShipFromFile(const std::string& path);
    void loadFromFile(const std::string& category);
    void generateShips();

    Response validation(const std::unique_ptr<Player>& player, size_t index) const;

    StoreClass m_class{StoreClass::None};
    std::map<std::unique_ptr<Ship>, int> m_ships{};
    std::vector<EngineClass> m_engines{};
};
