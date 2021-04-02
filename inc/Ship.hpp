#pragma once

#include "StockManagement.hpp"

enum class EngineClass {
    ChemicalFuel = 5,
    Antygravity = 10,
    DarkMatter = 25,
    Alcubierre = 100,
    ImpropabilityDrive = 9999
};

class Ship : public StockManagement {
private:
    std::string name_{};
    int crewSize_{};
    int avaiableSpace_{};
    EngineClass engine_{};

    void unload(const std::unique_ptr<Cargo>& cargo, int amount);

public:
    Ship(const std::string& name = "fajerwerka", int crewSize = 5, int avaiableSpace = 10, EngineClass engine = EngineClass::DarkMatter);

    std::string getName() const { return name_; }
    int getCrew() const { return crewSize_; }
    int getAvaiableSpace() const { return avaiableSpace_; }
    EngineClass getEngine() const { return engine_; }
    
    void load(std::unique_ptr<Cargo>&& cargo);
    void changePrice(const std::unique_ptr<Cargo>& cargo); 

    std::unique_ptr<Cargo> getCargo(size_t index, int amount);

};
