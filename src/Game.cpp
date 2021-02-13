#include "Game.hpp"

Game::Game(SolarSystem* planets, Player* player)
    : planets_(std::move(planets)), player_(player) {
}

void Game::optionHandler(size_t op) {
    switch (op) {
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
    std::cout << *planets_;
    std::cout << "Where do you want to travel?\n";
    int choice{};
    std::cin >> choice;
    auto destPlanet = planets_->getDestPlanet(choice);
    if (destPlanet) {
        planets_->travel(destPlanet, player_);
    } else {
        std::cout << "Select a valid planet.\n";
    }
}

void Game::buyOp() {
    planets_->getCurrPlanet()->getStore().purchaseCargo(1, 1, player_);
}

void Game::sellOp() {
    planets_->getCurrPlanet()->getStore().sellCargo(1, 1, player_);
}

void Game::printInfo() const {
    std::cout << "Current location: " << planets_->getCurrPlanet() ->getName() << '\n';
    std::cout << "Money avaiable: " << player_->getMoney() << '\n';
    std::cout << "Storage space avaiable: " << player_->getSpace() << '\n';
    std::cout << "Storage contains:\n" << *player_->getShip() << '\n';
}

void Game::run() {
    // while(player_->getMoney() > 0) {
        std::cout << std::string(50, '\n');
        planets_->orbit(20);
        printInfo();
        travelOp();
    // }
}
