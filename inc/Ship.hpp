#pragma once

#include <memory>
#include <string>
#include <vector>

#include "Cargo.hpp"

enum class EngineClass {
    ChemicalFuel = 1,
    Antygravity = 10,
    DarkMatter = 20,
    Alcubierre = 100,
    ImprobabilityDrive = 99999
};

class Ship {
private:
    std::string name_{};
    int crewSize_{};
    EngineClass engine_{};
    
    std::vector<std::unique_ptr<Cargo>> magazine_{};


public:
    Ship(const std::string& name = "", int crewSize = 0, EngineClass engine = EngineClass::ChemicalFuel);

    void load(std::unique_ptr<Cargo>& cargo);
    void unload(const std::unique_ptr<Cargo>& cargo);


};
