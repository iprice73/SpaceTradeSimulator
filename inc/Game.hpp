#pragma once

#include "SolarSystem.hpp"
#include "Time.hpp"

class Game {
private:
    std::shared_ptr<Time> time_{};
    std::unique_ptr<SolarSystem> planets_{};
    std::unique_ptr<Player> player_{};

    size_t menu() const;
    bool optionHandler(size_t op);
    void travelOp();
    void buyOp();
    void sellOp();
    void printInfo() const;
    void printWinScreen() const;
    void printLoseScreen() const;

public:
    Game();
    
    void run();

};
