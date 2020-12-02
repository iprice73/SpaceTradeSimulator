#pragma once

#include "ICargo.hpp"

constexpr double spiritus = 100.0;

class Alcohol : public Cargo {
private:
    double content_{};

public:
    Alcohol(const std::string&, int basePrice, int amount, double content);

    int getPrice() const override;
    double getContent() const { return content_; }

    bool operator==(const Alcohol& alco);

};
