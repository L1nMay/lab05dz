#include "Transaction.h"

Transaction::Transaction(const std::string& accountNumber, Type type, double amount) :
    accountNumber(accountNumber), type(type), amount(amount), timestamp(std::chrono::system_clock::now()) {}

std::string Transaction::getAccountNumber() const {
    return accountNumber;
}

Transaction::Type Transaction::getType() const {
    return type;
}

double Transaction::getAmount() const {
    return amount;
}

std::chrono::system_clock::time_point Transaction::getTimestamp() const {
    return timestamp;
}
