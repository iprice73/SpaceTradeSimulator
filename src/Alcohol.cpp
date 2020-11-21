#include "Alcohol.hpp"

Alcohol::Alcohol(const std::string& name, int basePrice, int amount, double content)
    : Cargo(name, basePrice, amount), content_(content) {}

int Alcohol::getPrice() const { return static_cast<int>(basePrice_ * (content_ + 1) / spiritus); }

bool Alcohol::operator==(const Alcohol& alco) {
    return alco.name_ == name_ && alco.content_ == content_;
}
