#include "Player.hpp"

Player::Player(const std::shared_ptr<Time>& time, int money)
    : money_(money), ship_(std::make_unique<Ship>(time)) {}

void Player::buy(std::unique_ptr<Cargo>&& cargo) {
    getShip()->load(std::move(cargo));
}

std::unique_ptr<Cargo> Player::sellCargo(size_t index, int amount) {
    return getShip()->getCargo(index, amount);
}

Player& Player::operator+=(int price) {
    money_ += price;
    return *this;
}

Player& Player::operator-=(int price) {
    money_ -= price;
    return *this;
}
