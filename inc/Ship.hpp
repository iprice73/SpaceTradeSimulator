#pragma once

#include "StockManagement.hpp"
#include "Time.hpp"

enum class EngineClass {
    ChemicalFuel = 5,
    Antygravity = 10,
    DarkMatter = 25,
    Alcubierre = 100,
    ImpropabilityDrive = 42000
};

class Ship : public StockManagement {
private:
    std::string name_{};
    int crewSize_{};
    int avaiableSpace_{};
    EngineClass engine_{};

    void unload(const cargo_ptr& cargo, int amount);
    int calculateAvaiableSpace(int newSpace) const;

public:
    Ship(const std::string& name = "fajerwerka", int crewSize = 5, int avaiableSpace = 10, EngineClass engine = EngineClass::DarkMatter);

    std::string getName() const { return name_; }
    int getCrew() const { return crewSize_; }
    int getAvaiableSpace() const { return avaiableSpace_; }
    EngineClass getEngine() const { return engine_; }

    void setName(const std::string& newName) { name_ = newName; }
    void setCrew(int newCrew) { crewSize_ = newCrew; }
    void setEngine(EngineClass newEngine) { engine_ = newEngine; }
    void setSpace(int amount);

    void load(cargo_ptr&& cargo);
    void changePrice(const cargo_vec& cargo);

    cargo_ptr getCargo(size_t index, int amount);
    bool operator==(const Ship& ship) { return name_ == ship.getName(); }
    bool operator!=(const Ship& ship) { return name_ != ship.getName(); }

    void nextDay(int days);
};
