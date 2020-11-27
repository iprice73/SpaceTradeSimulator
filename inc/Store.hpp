#pragma once

#include "Player.hpp"

enum class Response {
    Done,
    LackOfCargo,
    LackOfMoney,
    InvalidIndex
};

class Store {
private:
    std::vector<std::unique_ptr<Cargo>> stock_{};

    int getRand(int min, int max) const;

    void generateAlcos();
    void generateItems();
    void generateSpices();
    std::unique_ptr<Cargo> makeCargoToBuy(const std::unique_ptr<Cargo>& oldCargo, int amount);
    void removeFromStore(const std::unique_ptr<Cargo>& cargo, int amount);

public:
    Store();
    void showStore() const;
    Response buy(int index, int amount, Player* player);
    Response sell();

    friend std::ostream& operator<<(std::ostream& out, const Store& store);
};
