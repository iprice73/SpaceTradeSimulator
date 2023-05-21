#include "Chains.hpp"

Response IndexValidator::validate(const DealContext& context) {
    if (context.index > context.stock.size()) {
        return Response::InvalidIndex;
    }
    return Response::Done;
}

Response AmountValidator::validate(const DealContext& context) {
    if (context.amount < 0 || context.amount > context.stock[context.index]->getAmount()) {
        return Response::InvalidAmount;
    }
    return Response::Done;
}

Response SpaceValidator::validate(const DealContext& context) {
    if (context.amount > context.space && context.space != -1) {
        return Response::LackOfSpace;
    }
    return Response::Done;
}

Response MoneyValidator::validate(const DealContext& context) {
    int money_need = context.stock[context.index]->getPrice() * context.amount;
    if (context.money < money_need && context.money != -1) {
        return Response::LackOfMoney;
    }
    return Response::Done;
}