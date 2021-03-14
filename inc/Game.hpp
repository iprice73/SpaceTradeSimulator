#pragma once

#include "SolarSystem.hpp"

class Game {
private:
    std::unique_ptr<SolarSystem> planets_{};
    std::unique_ptr<Player> player_{};

    size_t menu() const;
    void optionHandler(size_t op);
    void travelOp();
    void buyOp();
    void sellOp();
    void printInfo() const;

public:
    Game();
    
    void run();

};
