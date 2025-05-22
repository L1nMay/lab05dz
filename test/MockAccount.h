#ifndef MOCKACCOUNT_H
#define MOCKACCOUNT_H

#include "Account.h"
#include <gmock/gmock.h>

class MockAccount : public Account {
public:
    MockAccount() : Account("mock", 0) {}
    virtual ~MockAccount() = default;

    MOCK_METHOD(bool, deposit, (double amount), (override));
    MOCK_METHOD(bool, withdraw, (double amount), (override));
    MOCK_METHOD(double, getBalance, (), (const, override));
};

#endif // MOCKACCOUNT_H
