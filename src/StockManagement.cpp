#include "StockManagement.hpp"

#include <algorithm>
#include <iomanip>

#include "Chains.hpp"

auto StockManagement::findExistingCargo(const std::unique_ptr<Cargo>& cargo) {
    auto pred = [&cargo](const auto& ptr){ return *ptr == *cargo; };
    return std::ranges::find_if(m_stock, pred);
}

void StockManagement::addCargo(std::unique_ptr<Cargo>&& cargo) {
    auto result_iterator = findExistingCargo(cargo);
    if (result_iterator == m_stock.end()) {
        m_stock.emplace_back(std::move(cargo));
    } else {
        int amount = cargo->getAmount();
        result_iterator->get()->addAmount(amount);
    }
}

void StockManagement::subtractCargo(const std::unique_ptr<Cargo>& cargo, int amount) {
    if (cargo) {
        cargo->subAmount(amount);
        eraseIfNoCargo();
    }
}

void StockManagement::eraseIfNoCargo() {
    auto pred = [](const auto& cargo){ return cargo->getAmount() == 0; };
    std::erase_if(m_stock, pred);
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