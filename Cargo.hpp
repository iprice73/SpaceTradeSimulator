#pragma once

#include <iostream>
#include <string>

class Cargo {
protected:
    std::string name_{};
    int basePrice_{};
    int amount_{};

public:
    Cargo(const std::string& name, int basePrice, int amount)
        : name_(name), basePrice_(basePrice), amount_(amount) { }

    virtual ~Cargo() { }

    std::string getName() const { return name_; }
    int getBasePrice() const { return basePrice_; }
    int getAmount() const { return amount_; }
    virtual int getPrice() const = 0;
};
