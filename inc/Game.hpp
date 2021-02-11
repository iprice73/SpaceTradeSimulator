#pragma once

#include "SolarSystem.hpp"

class Game {
private:
    SolarSystem* planets_;
    Player* player_;

public:
    Game(SolarSystem* planets, Player* player);

};
