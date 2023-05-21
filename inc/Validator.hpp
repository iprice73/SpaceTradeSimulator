#pragma once

#include "ICargo.hpp"

#include <memory>

enum class Response
{
    Done,
    LackOfMoney,
    LackOfSpace,
    InvalidAmount,
    InvalidIndex,
    EmptyStore,
    SameCargo
};

struct DealContext
{
    std::size_t index;
    int amount;
    int money;
    int space;
    const std::vector<std::unique_ptr<Cargo>> &stock;
};

class IValidator
{
public:
    ~IValidator() = default;
    virtual void setNextValidator(const std::shared_ptr<IValidator> &validator);
    virtual Response handle(const DealContext &context);
    virtual Response validate(const DealContext &context) = 0;

private:
    std::shared_ptr<IValidator> next_validator{nullptr};
};