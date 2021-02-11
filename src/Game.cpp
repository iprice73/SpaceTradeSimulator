#include "Game.hpp"

Game::Game(SolarSystem* planets, Player* player)
    : planets_(std::move(planets)), player_(player) {
}
