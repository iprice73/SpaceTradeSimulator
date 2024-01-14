#include "Player.hpp"

Player::Player(const std::shared_ptr<Time>& time, int money)
    : m_time(time), m_money(money), m_ship(std::make_unique<Ship>()) {
        m_time->addObserver(this);
    }

Player::~Player() {
    m_time->removeObserver(this);
}

void Player::moveCargoToShip(std::unique_ptr<Cargo>&& cargo) {
    m_ship->load(std::move(cargo));
}

std::unique_ptr<Cargo> Player::getCargoFromShip(size_t index, int amount) {
    auto cargo = m_ship->getCargo(index, amount);
    if (cargo.has_value()) {
        return std::move(cargo.value());
    }
    return nullptr;
}

void Player::addMoney(int price) {
    m_money += price;
}

void Player::subMoney(int price) {
    m_money -= price;
}

