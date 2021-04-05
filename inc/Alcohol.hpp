#pragma once

#include "ICargo.hpp"

constexpr double spiritus = 100.0;

class Alcohol : public Cargo {
private:
    double content_{};

public:
    Alcohol(const std::string&, int basePrice, int amount, double content);

    double getContent() const { return content_; }
    Alcohol& operator--();

    // Override from Cargo
    int getPrice() const override;

    // Override from Time
    void nextDay(int days) override;

};
