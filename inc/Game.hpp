#pragma once

#include "DialogManager.hpp"
#include "SolarSystem.hpp"
#include "Time.hpp"

class Game {
private:
    std::shared_ptr<Time> time_{};
    std::unique_ptr<SolarSystem> planets_{};
    std::unique_ptr<Player> player_{};

    DialogManager dialog{};

    size_t menu() const;
    bool optionHandler(size_t op);
    void travelOp();
    void buyOp();
    void buyShipOp();
    void sellOp();
    void printInfo() const;

public:
    Game();
    
    void run();

};
