#include "Game.hpp"

Game::Game()
    : time_(std::make_shared<Time>()), planets_(std::make_unique<SolarSystem>(time_)), player_(std::make_unique<Player>(time_, 1000)) {
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
        std::cout << "\n\033[1;31mInvalid option.\033[0m\n";
        break;
    }
}

void Game::buyOp() {
    std::cout << "\nPlanet's store:\n"
              << *planets_->getCurrPlanet()->getStore() << '\n'
              << "\033[1;34mEnter index and amount you would like to buy.\033[0m\n";
    size_t index;
    int amount;
    if (std::cin >> index >> amount) {
        planets_->getCurrPlanet()->getStore()->purchaseCargo(index - 1, amount, player_);
    } else {
        std::cout << "\033[1;31m\nSomething went wrong.\033[0m\n";
    }
}

void Game::sellOp() {
    std::cout << "\033[1;34mEnter index and amount you would like to sell.\033[0m\n";
    size_t index;
    int amount;
    if (std::cin >> index >> amount) {
        planets_->getCurrPlanet()->getStore()->sellCargo(index - 1, amount, player_);
    } else {
        std::cout << "\033[1;31m\nSomething went wrong.\033[0m\n";
    }
}

void Game::travelOp() {
    std::cout << "\n\033[1;34mWhere do you want to travel?\033[0m\n";
    planets_->printPlanets();
    std::cout << "Your choice: ";
    int choice{};
    if (std::cin >> choice) {
        if (auto destPlanet(planets_->getDestPlanet(choice)); destPlanet) {
            planets_->travel(destPlanet, player_);
        } else {
            std::cout << "\033[1;31m\nSelect a valid planet.\033[0m\n";
        }
    } else {
        std::cout << "\033[1;31m\nSelect a valid planet.\033[0m\n";
    }
}

void Game::printInfo() const {
    std::cout << "\nCurrent location: " << planets_->getCurrPlanet()->getName() << '\n'
              << "Money avaiable: " << player_->getMoney() << '\n'
              << "Storage space avaiable: " << player_->getSpace() << '\n'
              << "Storage:\n"
              << *player_->getShip() << '\n';
}

void Game::printWinScreen() const {
    std::cout << " __     __ ____   _    _  __          __ _____  _   _\n"
              << " \\ \\   / // __ \\ | |  | | \\ \\        / /|_   _|| \\ | |\n"
              << "  \\ \\_/ /| |  | || |  | |  \\ \\  /\\  / /   | |  |  \\| |\n"
              << "   \\   / | |  | || |  | |   \\ \\/  \\/ /    | |  | . ` |\n"
              << "    | |  | |__| || |__| |    \\  /\\  /    _| |_ | |\\  |\n"
              << "    |_|   \\____/  \\____/      \\/  \\/    |_____||_| \\_|\n\n";
}

void Game::printLoseScreen() const {
    std::cout << "__     __ ____   _    _    _____  _    _   _____  _  __\n"
              << "\\ \\   / // __ \\ | |  | |  / ____|| |  | | / ____|| |/ /\n"
              << " \\ \\_/ /| |  | || |  | | | (___  | |  | || |     | ' / \n"
              << "  \\   / | |  | || |  | |  \\___ \\ | |  | || |     |  < \n"
              << "   | |  | |__| || |__| |  ____) || |__| || |____ | . \\ \n"
              << "   |_|   \\____/  \\____/  |_____/  \\____/  \\_____||_|\\_\\\n\n";
}

void Game::run() {
    planets_->orbit(Store::getRand(100, 300));
    while (1) {
        if (int money(player_->getMoney()); money < 10'000 && money > 0) {
            printInfo();
            size_t op = menu();
            optionHandler(op);
        } else if (money > 10'000) {
            printWinScreen();
            break;
        } else {
            printLoseScreen();
            break;
        }
    }
}
