#include <iostream>

#include "Game.hpp"

int main() {
    SolarSystem planets;
    Player player(1000);

    Game game(&planets, &player);
    game.run();

    return 0;
}
