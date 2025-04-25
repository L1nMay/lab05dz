#include "Account.h"

Account::Account(const std::string& accountNumber, double initialBalance)
    : accountNumber(accountNumber), initialBalance(initialBalance) {
}

bool Account::deposit(double amount) {
    if (amount > 0) {
        initialBalance += amount;
        return true;
    }
    return false;
}

bool Account::withdraw(double amount) {
    if (amount > 0 && amount <= initialBalance) {
        initialBalance -= amount;
        return true;
    }
    return false;
}

double Account::getBalance() const {
    return initialBalance;
}
