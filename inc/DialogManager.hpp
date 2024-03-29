#pragma once

#include "Store.hpp"

class DialogManager {
public:
    void printStore(const cargo_vec& store) const;
    void printDealSummary() const;
    void printMenu() const;
    void printLoseScreen() const;
    void printWinScreen() const;
};