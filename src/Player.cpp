#include "Player.hpp"

Player::Player(int money, Ship* ship)
    : money_(money), ship_(ship) {}

Player& Player::operator+=(int price) {
    money_ += price;
    return *this;
}

Player& Player::operator-=(int price) {
    money_ -= price;
    return *this;
}

void Player::buy(std::unique_ptr<Cargo>&& cargo) {
    getShip()->load(std::move(cargo));
}

std::unique_ptr<Cargo> Player::sellCargo(size_t index, int amount) {
    return getShip()->getCargo(index, amount);
}
