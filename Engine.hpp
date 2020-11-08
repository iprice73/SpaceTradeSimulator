#pragma once

#include "Cargo.hpp"


class Engine : public Cargo {
private:
    // nothing for now

public:
    Engine(const std::string&, int basePrice, int maount);

    int getPrice() const override;

};
