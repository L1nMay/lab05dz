#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
public:
    Account() : accountNumber("default"), initialBalance(0.0) {} // Constructor по умолчанию
    Account(const std::string& accountNumber, double initialBalance);
    bool deposit(double amount);
    bool withdraw(double amount);
    double getBalance() const;

private:
    std::string accountNumber;
    double initialBalance;
};

#endif
