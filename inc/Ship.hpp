#pragma once

#include <memory>
#include <string>
#include <vector>

#include "StockManagement.hpp"

enum class EngineClass {
    ChemicalFuel = 1,
    Antygravity = 10,
    DarkMatter = 20,
    Alcubierre = 100,
    ImpropabilityDrive = 99999
};

class Ship : public StockManagement {
private:
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
    std::unique_ptr<Cargo> getCargo(size_t index, int amount);
    void unload(const std::unique_ptr<Cargo>& cargo, int amount);
};
