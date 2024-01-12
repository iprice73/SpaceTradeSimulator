#include "Player.hpp"

Player::Player(const std::shared_ptr<Time>& time, int money)
    : time_(time), money_(money), ship_(std::make_unique<Ship>()) {
        time_->addObserver(this);
    }

Player::~Player() {
    time_->removeObserver(this);
}

void Player::buy(std::unique_ptr<Cargo>&& cargo) {
    getShip()->load(std::move(cargo));
}

std::unique_ptr<Cargo> Player::sellCargo(size_t index, int amount) {
    auto cargo = getShip()->getCargo(index, amount);
    if (cargo.has_value()) {
        return std::move(cargo.value());
    }
    return nullptr;
}

void Player::addMoney(int price) {
    money_ += price;
}

void Player::subMoney(int price) {
    money_ -= price;
}

