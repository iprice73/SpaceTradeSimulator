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
    std::cout << "\033[1;34mEnter index and amount you would like to buy.\033[0m\n";
}

void DialogManager::pristDealSummary() const {
    std::string horizontalSeparator(42, '=');
    std::cout << "\033[1;32m" << horizontalSeparator << std::endl;
    std::cout << std::setw(10) << std::left << '|' << "Transaction Completed" << std::setw(11) << std::right << '|' << std::endl;
    std::cout << horizontalSeparator << std::endl;
    std::cout << std::setw(20) << std::left << "Cargo:" << std::setw(21) << "cargoN22ame" << std::right << '|' << std::endl;
    std::cout << std::setw(20) << std::left << "Amount:" << std::setw(21) << "amountBought" << std::right << '|' << std::endl;
    std::cout << std::setw(20) << std::left << "Cost:" << std::setw(21) << std::fixed << std::setprecision(2) << "moneySpent" << std::right << '|' << std::endl;
    std::cout << std::setw(20) << std::left << "Money Left:" << std::setw(21) << std::fixed << std::setprecision(2) << "moneyLeft" << std::right << '|' << std::endl;
    std::cout << std::setw(20) << std::left << "Storage Left:" << std::setw(21)<< "storageLeft" << std::right << '|' << std::endl;
    std::cout << horizontalSeparator << "\033[0m" << std::endl;
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