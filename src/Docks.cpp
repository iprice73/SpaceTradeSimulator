#include "Docks.hpp"

#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

SpaceCraftStore::SpaceCraftStore(StoreClass storeClass)
    : m_class(storeClass) {
    generateShips();
}

std::map<std::string, EngineClass> engineData{
    {"ChemicalFuel", EngineClass::ChemicalFuel},
    {"Antygravity", EngineClass::Antygravity},
    {"DarkMatter", EngineClass::DarkMatter},
    {"Alcubierre", EngineClass::Alcubierre},
    {"ImpropabilityDrive", EngineClass::ImpropabilityDrive}};

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
    fs::path path{"../res/"};
    for (const auto& dirEntry : fs::directory_iterator(path)) {
        if (dirEntry.path().string().find(category) != std::string::npos) {
            parseShipFromFile(dirEntry.path().string());
        }
    }
}

void SpaceCraftStore::generateShips() {
    switch (m_class) {
    case StoreClass::Basic:
        loadFromFile("basic");
        break;
    case StoreClass::Advanced:
        loadFromFile("advanced");
    default:
        break;
    }
}

void SpaceCraftStore::printShips() const {
    std::cout << "Avaiable ships:\n";
    size_t i = 1;
    for (const auto& el : m_ships) {
        auto&& ship = el.first;
        std::cout << i++ << ". " << ship->getName() << ' ' << ship->getCrew() << ' ' << ship->getAvaiableSpace() << ' ' << el.second << '\n';
    }
}

void SpaceCraftStore::buyEngine([[maybe_unused]] const std::unique_ptr<Player>& player) {
}

void SpaceCraftStore::buyShip([[maybe_unused]] const std::unique_ptr<Player>& player) {
}
