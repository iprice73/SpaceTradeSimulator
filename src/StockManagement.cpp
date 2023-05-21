#include "StockManagement.hpp"

#include <algorithm>
#include <iomanip>

#include "Chains.hpp"

void StockManagement::addCargo(std::unique_ptr<Cargo>&& cargo) {
    int amount = cargo->getAmount();
    if (auto existingCargoIt (std::find_if(m_stock.begin(), m_stock.end(),
                                            [&cargo](const auto& ptr) { return *ptr == *cargo; }));
        existingCargoIt == m_stock.end()) {
        m_stock.push_back(std::move(cargo));
    } else {
        **existingCargoIt += amount;
    }
}

void StockManagement::removeCargo(const std::unique_ptr<Cargo>& cargo, int amount) {
    if (cargo->getAmount() == amount) {
        m_stock.erase(std::remove(m_stock.begin(), m_stock.end(), cargo), m_stock.end());
    } else {
        *cargo -= amount;
    }
}

Response StockManagement::validation(size_t index, int amount, int money, int space) const {
    auto validators = setupValidators();
    setupChain(validators);
    DealContext context{index, amount, money, space, m_stock};

    return validators[0]->handle(context);
}

std::vector<std::shared_ptr<IValidator>> StockManagement::setupValidators() const {
    std::vector<std::shared_ptr<IValidator>> validators{};

    validators.push_back(std::make_shared<IndexValidator>());
    validators.push_back(std::make_shared<AmountValidator>());
    validators.push_back(std::make_shared<SpaceValidator>());
    validators.push_back(std::make_shared<MoneyValidator>());

    return validators;
}

void StockManagement::setupChain(const std::vector<std::shared_ptr<IValidator>>& validators) const {
    for (std::size_t i = 0; i < validators.size() - 1; i++) {
        validators[i]->setNextValidator(validators[i + 1]);
    }
}

std::string StockManagement::handleResponse(Response re) const {
    switch (re) {
    case Response::InvalidIndex:
        return "\033[1;31mEnter proper index.\033[0m";
    case Response::InvalidAmount:
        return "\033[1;31mEnter proper amount.\033[0m";
    case Response::LackOfMoney:
        return "\033[1;31mYou don't have money for this.\033[0m";
    case Response::LackOfSpace:
        return "\033[1;31mYou don't have enough space.\033[0m";
    case Response::Done:
        return "\033[1;32mTransaction completed.\033[0m";
    default:
        return "How did you get there?";
    }
}

std::ostream& operator<<(std::ostream& out, const StockManagement& stock) {
    std::string horizontalSeparator(40, '=');
    int i = 0;

    out << horizontalSeparator
        << "\n"
        << "|| Cargo avaiable"
        << std::setw(14) << "| QTY "
        << "| PRICE "
        << "||\n"
        << horizontalSeparator << "\n";

    for (const auto& el : stock.m_stock) {
        out << "|| "
            << std::setw(2) << ++i << ". "
            << std::setw(17) << std::left << el->getName();

        out << std::setw(4) << "|" << std::left << el->getAmount() << " | "
            << std::setw(5) << std::right << el->getPrice() << " ||\n";
    }
    out << horizontalSeparator << "\n";

    return out;
}
