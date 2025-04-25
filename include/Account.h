#ifndef BANKING_ACCOUNT_H
#define BANKING_ACCOUNT_H

#include <string>

class Account {
public:
    Account(const std::string& accountNumber, double initialBalance);
    virtual ~Account() = default;

    std::string getAccountNumber() const;
    double getBalance() const;
    virtual void deposit(double amount);
    virtual bool withdraw(double amount);

private:
    std::string accountNumber;
    double balance;
};

#endif // BANKING_ACCOUNT_H
