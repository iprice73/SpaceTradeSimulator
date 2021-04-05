#include "Alcohol.hpp"

Alcohol::Alcohol(const std::string& name, int basePrice, int amount, double content)
    : Cargo(name, basePrice, amount), content_(content) {}

int Alcohol::getPrice() const {
    return static_cast<int>(basePrice_ * (content_ + 1) / spiritus);
}

Alcohol& Alcohol::operator--() {
    content_ > 0.0 ? content_ -= 0.5 : basePrice_ = 0;

    return *this;
}

void Alcohol::nextDay(int days) {
    for (int i = 0; i < days; i++) {
        this->operator--();
    }
}
