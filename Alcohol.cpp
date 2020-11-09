#include "Alcohol.hpp"

Alcohol::Alcohol(const std::string& name, int basePrice, int amount, double content)
    : Cargo(name, basePrice, amount), content_(content) {}

int Alcohol::getPrice() const { return static_cast<int>(basePrice_ * content_ / spiritus); }
