#ifndef MOCKACCOUNT_H
#define MOCKACCOUNT_H

#include "Account.h"
#include <gmock/gmock.h>

class MockAccount : public Account {
public:
    MockAccount(const std::string& accountNumber = "mock", double initialBalance = 0)
        : Account(accountNumber, initialBalance) {}

    MOCK_METHOD(bool, deposit, (double amount));
    MOCK_METHOD(bool, withdraw, (double amount));
    MOCK_METHOD(double, getBalance, (), (const));
};

#endif // MOCKACCOUNT_H
