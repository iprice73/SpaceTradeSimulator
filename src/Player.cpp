#include "Player.hpp"

Player::Player(int money, Ship* ship)
    : money_(money), ship_(ship) {}

Player& Player::operator-=(int price) {
    money_ -= price;
    return *this;
}

void Player::buy(std::unique_ptr<Cargo>&& cargo, int price) {
    getShip()->load(std::move(cargo));
    money_ -= price;
}

void Player::sell(const std::unique_ptr<Cargo>& cargo, int amount) {
    getShip()->unload(cargo, amount);
    money_ += cargo->getPrice() * amount;
}
