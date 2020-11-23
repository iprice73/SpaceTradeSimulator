#pragma once

#include <memory>
#include <string>
#include <vector>

#include "Alcohol.hpp"
#include "Item.hpp"
#include "Spice.hpp"

enum class EngineClass {
    ChemicalFuel = 1,
    Antygravity = 10,
    DarkMatter = 20,
    Alcubierre = 100,
    ImprobabilityDrive = 99999
};

class Ship {
private:
    std::vector<std::unique_ptr<Cargo>> magazine_{};

    std::string name_{};
    int crewSize_{};
    EngineClass engine_{};

public:
    Ship(const std::string& name = "fajerwerka", int crewSize = 0, EngineClass engine = EngineClass::ChemicalFuel);

    std::string getName() const { return name_; }

};
