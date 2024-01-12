#include "DialogManager.hpp"

#include <iostream>
#include <iomanip>

void DialogManager::printStore(const cargo_vec& stock) const {
    std::string horizontalSeparator(40, '=');
    int i = 0;

    std::cout << horizontalSeparator
        << "\n"
        << "|| Cargo avaiable"
        << std::setw(14) << "| QTY "
        << "| PRICE "
        << "||\n"
        << horizontalSeparator << "\n";

    for (const auto& el : stock) {
        std::cout << "|| "
            << std::setw(2) << ++i << ". "
            << std::setw(17) << std::left << el->getName();

        std::cout << std::setw(4) << "|" << std::left << el->getAmount() << " | "
            << std::setw(5) << std::right << el->getPrice() << " ||\n";
    }
    std::cout << horizontalSeparator << "\n";
}

void DialogManager::pristDealSummary() const {

}

void DialogManager::printMenu() const {
    std::cout << "Avaiable options:\n"
              << "1. Buy.\n"
              << "2. Buy ship.\n"
              << "3. Sell.\n"
              << "4. Travel.\n"
              << "5. Exit.\n"
              << "Your choice: ";
}

void DialogManager::printWinScreen() const {
    std::cout << " __     __ ____   _    _  __          __ _____  _   _\n"
              << " \\ \\   / // __ \\ | |  | | \\ \\        / /|_   _|| \\ | |\n"
              << "  \\ \\_/ /| |  | || |  | |  \\ \\  /\\  / /   | |  |  \\| |\n"
              << "   \\   / | |  | || |  | |   \\ \\/  \\/ /    | |  | . ` |\n"
              << "    | |  | |__| || |__| |    \\  /\\  /    _| |_ | |\\  |\n"
              << "    |_|   \\____/  \\____/      \\/  \\/    |_____||_| \\_|\n\n";
}

void DialogManager::printLoseScreen() const {
    std::cout << "__     __ ____   _    _    _____  _    _   _____  _  __\n"
              << "\\ \\   / // __ \\ | |  | |  / ____|| |  | | / ____|| |/ /\n"
              << " \\ \\_/ /| |  | || |  | | | (___  | |  | || |     | ' / \n"
              << "  \\   / | |  | || |  | |  \\___ \\ | |  | || |     |  < \n"
              << "   | |  | |__| || |__| |  ____) || |__| || |____ | . \\ \n"
              << "   |_|   \\____/  \\____/  |_____/  \\____/  \\_____||_|\\_\\\n\n";
}