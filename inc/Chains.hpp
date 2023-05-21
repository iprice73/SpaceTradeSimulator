#include "Validator.hpp"

class IndexValidator : public IValidator {
public:
    Response validate(const DealContext& context) override;
};

class AmountValidator : public IValidator {
public:
    Response validate(const DealContext& context) override;
};

class MoneyValidator : public IValidator {
public:
    Response validate(const DealContext& context) override;
};

class SpaceValidator : public IValidator {
public:
    Response validate(const DealContext& context) override;
};