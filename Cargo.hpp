#pragma once

#include <string>

class Cargo {
private:
    std::string name_{};
    int basePrice_{};
    int amount_{};

public:
    Cargo(const std::string& name, int basePrice, int amount)
        : name_(name), basePrice_(basePrice), amount_(amount) {}

    std::string getName() const { return name_; }
    int getBasePrice() const { return basePrice_; }
    int getAmount() const { return amount; }
    int getPrice() const = 0;
}
