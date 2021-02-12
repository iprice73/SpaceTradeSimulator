#include "Game.hpp"

Game::Game(SolarSystem* planets, Player* player)
    : planets_(std::move(planets)), player_(player) {
}

void Game::optionHandler(size_t op) {
    switch (op)
    {
    case 1:
        travelOp();
        break;
    case 2:
        buyOp();
        break;
    case 3:
        sellOp();
        break;
    case 4:
        exit(0);
    default:
        break;
    }
}

void Game::travelOp() {
    std::cout << "Current location: " << planets_->getCurrPlanet()->getName() << '\n';
    std::cout << planets_->getCurrPlanet()->getStore() << '\n';
    std::cout << *planets_;
    std::cout << "Where do you want to travel?\n";
    int choice{};
    std::cin >> choice;
    auto destPlanet = planets_->getDestPlanet(choice);
    if (destPlanet) {
        planets_->travel(destPlanet, player_);
    }
    std::cout << "Current location: " << planets_->getCurrPlanet()->getName() << '\n';
    std::cout << planets_->getCurrPlanet()->getStore() << '\n';
}

void Game::buyOp() {

}

void Game::sellOp() {
    
}
