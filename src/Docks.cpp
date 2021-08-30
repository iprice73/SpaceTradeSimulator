#include "Docks.hpp"

#include <filesystem>
#include <fstream>
#include <map>

namespace fs = std::filesystem;

const std::map<Response, std::string> messages{
    {Response::EmptyStore, "Store is empty."},
    {Response::InvalidIndex, "Invalid index."},
    {Response::SameCargo, "You already have that ship."},
    {Response::InvalidAmount, "You need ship with more storage space."},
    {Response::LackOfMoney, "Youd don't have enough money."},
    {Response::Done, "Transaction completed."}};

std::map<std::string, EngineClass> engineData{
    {"ChemicalFuel", EngineClass::ChemicalFuel},
    {"Antygravity", EngineClass::Antygravity},
    {"DarkMatter", EngineClass::DarkMatter},
    {"Alcubierre", EngineClass::Alcubierre},
    {"ImpropabilityDrive", EngineClass::ImpropabilityDrive}};

SpaceCraftStore::SpaceCraftStore(StoreClass storeClass)
    : m_class(storeClass) {
    generateShips();
}

void SpaceCraftStore::parseShipFromFile(const std::string& path) {
    std::fstream file;
    file.open(path, file.in);
    std::string name{}, engine{};
    int crew{}, space{}, price{};
    if (file.is_open()) {
        file >> name;
        file >> crew;
        file >> space;
        file >> engine;
        file >> price;
        file.close();
    }
    m_ships[std::make_unique<Ship>(name, crew, space, engineData[engine])] = price;
}

void SpaceCraftStore::loadFromFile(const std::string& category) {
    const fs::path path{"../res/"};
    for (const auto& dirEntry : fs::directory_iterator(path)) {
        if (dirEntry.path().string().find(category) != std::string::npos) {
            parseShipFromFile(dirEntry.path().string());
        }
    }
}

void SpaceCraftStore::generateShips() {
    loadFromFile((m_class == StoreClass::Basic) ? "basic" : "advanced");
}

void SpaceCraftStore::printShips() const {
    size_t i = 1;
    for (const auto& el : m_ships) {
        auto&& ship = el.first;
        std::cout << i++ << ". " << ship->getName() << ' ' << ship->getCrew() << ' ' << ship->getAvaiableSpace() << ' ' << el.second << '\n';
    }
}

void SpaceCraftStore::editShip(const std::unique_ptr<Player>& player, const std::unique_ptr<Ship>& newShip) const {
    player->getShip()->setName(newShip->getName());
    player->getShip()->setCrew(newShip->getCrew());
    player->getShip()->setSpace(newShip->getAvaiableSpace());
    player->getShip()->setEngine(newShip->getEngine());
}

auto SpaceCraftStore::getShip(size_t index) const {
    return std::next(m_ships.begin(), index);
}

Response SpaceCraftStore::validation(const std::unique_ptr<Player>& player, size_t index) const {
    if (m_ships.empty()) {
        return Response::EmptyStore;
    } else if (index > m_ships.size()) {
        return Response::InvalidIndex;
    } else if (player->getMoney() < getShip(index)->second) {
        return Response::LackOfMoney;
    } else if (*player->getShip() == *getShip(index)->first) {
        return Response::SameCargo;
    } else if (player->getSpace() > getShip(index)->first->getAvaiableSpace()) {
        return Response::InvalidAmount;
    }

    return Response::Done;
}

// TODO: empty stores both space and cargo
void SpaceCraftStore::buyShip(const std::unique_ptr<Player>& player, size_t index) {
    auto re = validation(player, index);
    if (re == Response::Done) {
        auto shipPtr = getShip(index);
        editShip(player, shipPtr->first);
        m_ships.erase(shipPtr->first);
        *player -= shipPtr->second;
    }
    std::cout << messages.at(re) << '\n';
}

void SpaceCraftStore::buyEngine([[maybe_unused]] const std::unique_ptr<Player>& player) {
}
