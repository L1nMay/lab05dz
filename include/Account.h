#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
public:
    Account() : accountNumber("default"), initialBalance(0.0) {}
    Account(const std::string& accountNumber, double initialBalance);

    virtual bool deposit(double amount);
    virtual bool withdraw(double amount);
    virtual double getBalance() const;
    virtual ~Account() = default;

private:
    std::string accountNumber;
    double initialBalance;
};

#endif
