#pragma once

#include "SolarSystem.hpp"

class Game {
private:
    SolarSystem* planets_{};
    Player* player_{};

    size_t menu() const;
    void optionHandler(size_t op);
    void travelOp();
    void buyOp();
    void sellOp();
    void printInfo() const;

public:
    Game(SolarSystem* planets, Player* player);
    
    void run();

};
