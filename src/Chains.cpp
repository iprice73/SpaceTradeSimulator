#include "Chains.hpp"

#include <iostream>

Response IndexValidator::validate(const DealContext& context) {
    if (context.index > context.stock.size()) {
        std::cout << "\033[1;31mEnter proper index.\033[0m";
        return Response::InvalidIndex;
    }
    return Response::Done;
}

Response AmountValidator::validate(const DealContext& context) {
    if (context.amount <= 0 || context.amount > context.stock[context.index]->getAmount()) {
        std::cout << "\033[1;31mEnter proper amount.\033[0m";
        return Response::InvalidAmount;
    }
    return Response::Done;
}

Response SpaceValidator::validate(const DealContext& context) {
    if (context.amount > context.space && context.space != -1) {
        std::cout << "\033[1;31mYou don't have enough space.\033[0m";
        return Response::LackOfSpace;
    }
    return Response::Done;
}

Response MoneyValidator::validate(const DealContext& context) {
    int money_need = context.stock[context.index]->getPrice() * context.amount;
    if (context.money < money_need && context.money != -1) {
        std::cout << "\033[1;31mYou don't have money for this.\033[0m";
        return Response::LackOfMoney;
    }
    return Response::Done;
}