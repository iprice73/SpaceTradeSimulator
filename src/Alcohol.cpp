#include "Alcohol.hpp"

Alcohol::Alcohol(const std::string& name, int basePrice, int amount, double content)
    : Cargo(name, basePrice, amount), content_(content) {
}

int Alcohol::getPrice() const {
    return basePrice_ + static_cast<int>(static_cast<double>(basePrice_) * content_);
}

cargo_ptr Alcohol::clone(int amount) const {
    return std::make_unique<Alcohol>(name_, basePrice_, amount, content_);
}

void Alcohol::decreaseContent() {
    content_ > 0.0 ? content_ -= 0.02 : basePrice_ = 0;
}

void Alcohol::nextDay(int days) {
    for (int i = 0; i < days; i++) {
        decreaseContent();
    }
}
