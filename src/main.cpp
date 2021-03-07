#include <iostream>

#include "Game.hpp"

int main() {
    SolarSystem planets;
    Ship ship;
    Player player(1000, &ship);

    Game game(&planets, &player);
    game.run();

    return 0;
}
