#pragma once

#include <optional>

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
    std::string m_name{};
    int m_crewSize{};
    int m_avaiableSpace{};
    EngineClass m_engine{};

    void unload(const cargo_ptr& cargo, int amount);
    int calculateAvaiableSpace(int newSpace) const;

public:
    Ship(const std::string& name = "fajerwerka", int crewSize = 5, int avaiableSpace = 10, EngineClass engine = EngineClass::DarkMatter);

    std::string getName() const { return m_name; }
    int getCrew() const { return m_crewSize; }
    int getAvaiableSpace() const { return m_avaiableSpace; }
    EngineClass getEngine() const { return m_engine; }

    void setName(const std::string& newName) { m_name = newName; }
    void setCrew(int newCrew) { m_crewSize = newCrew; }
    void setEngine(EngineClass newEngine) { m_engine = newEngine; }
    void setSpace(int amount);

    void load(cargo_ptr&& cargo);
    void changePrice(const cargo_vec& cargo);

    std::optional<cargo_ptr> getCargo(size_t index, int amount);
    bool operator==(const Ship& ship) { return m_name == ship.getName(); }
    bool operator!=(const Ship& ship) { return m_name != ship.getName(); }

    void nextDay(int days);
};
