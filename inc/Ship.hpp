#pragma once

#include "StockManagement.hpp"
#include "Time.hpp"

enum class EngineClass {
    ChemicalFuel = 5,
    Antygravity = 10,
    DarkMatter = 25,
    Alcubierre = 100,
    ImpropabilityDrive = 9999
};

class Ship : public StockManagement, public Observer {
private:
    std::shared_ptr<Time> time_{};
    std::string name_{};
    int crewSize_{};
    int avaiableSpace_{};
    EngineClass engine_{};

    void unload(const cargo_ptr& cargo, int amount);

public:
    Ship(const std::shared_ptr<Time>& time, const std::string& name = "fajerwerka", int crewSize = 5, int avaiableSpace = 10, EngineClass engine = EngineClass::DarkMatter);
    ~Ship();

    std::string getName() const { return name_; }
    int getCrew() const { return crewSize_; }
    int getAvaiableSpace() const { return avaiableSpace_; }
    EngineClass getEngine() const { return engine_; }

    void load(cargo_ptr&& cargo);
    void changePrice(const cargo_ptr& cargo);

    cargo_ptr getCargo(size_t index, int amount);

    void nextDay(int days) override;
};
