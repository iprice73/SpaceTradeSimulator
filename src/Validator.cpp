#include "Validator.hpp"

void IValidator::setNextValidator(const std::shared_ptr<IValidator>& validator) {
    next_validator = validator;
}

Response IValidator::handle(const DealContext& context) {
    auto result =  validate(context);
    if (result != Response::Done) return result;
    if (next_validator) {
        return next_validator->handle(context);
    }
    return Response::Done;
}