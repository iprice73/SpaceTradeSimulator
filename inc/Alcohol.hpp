#pragma once

#include "ICargo.hpp"

class Alcohol : public Cargo {
private:
    double content_{};
    const int maxAlcoAMount{30};

public:
    Alcohol(const std::string&, int basePrice, int amount, double content);

    double getContent() const { return content_; }
    void decreaseContent();

    // Override from Cargo
    int getPrice() const override;
    cargo_ptr clone(int amount) const override;

    // Override from Time
    void nextDay(int days) override;

};
