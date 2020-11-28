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
    ImpropabilityDrive = 99999
};

class Ship {
private:
    std::vector<std::unique_ptr<Cargo>> magazine_{};

    std::string name_{};
    int crewSize_{};
    int avaiableSpace_{};
    EngineClass engine_{};

public:
    Ship(const std::string& name = "fajerwerka", int crewSize = 0, int avaiableSpace = 10, EngineClass engine = EngineClass::ChemicalFuel);

    std::string getName() const { return name_; }
    int getCrew() const { return crewSize_; }
    int getAvaiableSpace() const { return avaiableSpace_; }
    EngineClass getEngine() const { return engine_; }
    void load(std::unique_ptr<Cargo>&& cargo);
    void show() const;

    friend std::ostream& operator<<(std::ostream& out, const Ship& ship);
};
