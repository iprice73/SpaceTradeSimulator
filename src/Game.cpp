#include "Game.hpp"

Game::Game(SolarSystem* planets, Player* player)
    : planets_(std::move(planets)), player_(player) {
}

size_t Game::menu() const {
    std::cout << "Avaiable options:\n"
              << "1. Buy.\n"
              << "2. Sell.\n"
              << "3. Travel.\n"
              << "4. Exit.\n"
              << "Your choice: ";
    size_t choice;
    std::cin >> choice;

    return choice;
}

void Game::optionHandler(size_t op) {
    switch (op) {
    case 1:
        buyOp();
        break;
    case 2:
        sellOp();
        break;
    case 3:
        travelOp();
        break;
    case 4:
        exit(0);
    default:
        break;
    }
}

void Game::buyOp() {
    std::cout << "\nPlanet's store:\n"
              << planets_->getCurrPlanet()->getStore() << '\n'
              << "Enter index and amount you would like to buy.\n";
    size_t index;
    int amount;
    std::cin >> index >> amount;
    planets_->getCurrPlanet()->getStore().purchaseCargo(index - 1, amount, player_);
}

void Game::sellOp() {
    std::cout << "Enter index and amount you would like to sell.\n";
    size_t index;
    int amount;
    std::cin >> index >> amount;
    planets_->getCurrPlanet()->getStore().sellCargo(index - 1, amount, player_);
}

void Game::travelOp() {
    std::cout << "\nWhere do you want to travel?\n";
    planets_->show(); 
    std::cout << "Your choice: ";
    int choice{};
    std::cin >> choice;
    auto destPlanet = planets_->getDestPlanet(choice);
    if (destPlanet) {
        planets_->travel(destPlanet, player_);
    } else {
        std::cout << "Select a valid planet.\n";
        travelOp();
    }
}

void Game::printInfo() const {
    std::cout << "\nCurrent location: " << planets_->getCurrPlanet()->getName() << '\n'
              << "Money avaiable: " << player_->getMoney() << '\n'
              << "Storage space avaiable: " << player_->getSpace() << '\n'
              << "Storage:\n"
              << *player_->getShip() << '\n';
}

void Game::run() {
    planets_->orbit(rand() % 300 + 100);
    size_t op;
    while (player_->getMoney() > 100) {
        printInfo();
        op = menu();
        optionHandler(op);
    }
}
