#pragma once

#include <memory>
#include <vector>
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
    void setBasePrice(int newPrice) { basePrice_ = newPrice; };

    virtual int getPrice() const = 0;
    virtual std::unique_ptr<Cargo> clone(int amount) const = 0;

    void addAmount(int newAmount) {
        amount_ += newAmount;
    }

    void subAmount(int newAmount) {
        amount_ -= newAmount;
    }

    bool operator==(const Cargo& cargo) {
        return name_ == cargo.getName();
    }
};

using cargo_ptr = std::unique_ptr<Cargo>;
using cargo_vec = std::vector<std::unique_ptr<Cargo>>;
