#pragma once

#include <string>

#include "Time.hpp"
class Cargo : public Observer {
protected:
    std::string name_{};
    int basePrice_{};
    int amount_{};

public:
    Cargo(const std::string& name, int basePrice, int amount)
        : name_(name), basePrice_(basePrice), amount_(amount) {}

    virtual ~Cargo() = default;

    std::string getName() const { return name_; }
    int getBasePrice() const { return basePrice_; }
    int getAmount() const { return amount_; }
    virtual int getPrice() const = 0;

    void setPrice(int newPrice) {
        basePrice_ = newPrice;
    }

    Cargo& operator-=(int newAmount) {
        amount_ -= newAmount;
        return *this;
    }

    Cargo& operator+=(int newAmount) {
        amount_ += newAmount;
        return *this;
    }

    bool operator==(const Cargo& cargo) {
        return name_ == cargo.getName();
    }
};
