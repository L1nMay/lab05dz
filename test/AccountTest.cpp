#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Account.h"

#include <stdexcept>

TEST(AccountTest, ConstructorValidInitialBalance) {
    Account account("12345", 100.0);
    ASSERT_EQ(100.0, account.getBalance());
    ASSERT_EQ("12345", account.getAccountNumber());
}

TEST(AccountTest, ConstructorInvalidInitialBalance) {
    ASSERT_THROW(Account("12345", -100.0), std::invalid_argument);
}

TEST(AccountTest, DepositValidAmount) {
    Account account("12345", 100.0);
    account.deposit(50.0);
    ASSERT_EQ(150.0, account.getBalance());
}

TEST(AccountTest, DepositInvalidAmount) {
    Account account("12345", 100.0);
    ASSERT_THROW(account.deposit(-50.0), std::invalid_argument);
    ASSERT_THROW(account.deposit(0.0), std::invalid_argument);
}

TEST(AccountTest, WithdrawSufficientFunds) {
    Account account("12345", 100.0);
    bool success = account.withdraw(50.0);
    ASSERT_TRUE(success);
    ASSERT_EQ(50.0, account.getBalance());
}

TEST(AccountTest, WithdrawInsufficientFunds) {
    Account account("12345", 100.0);
    bool success = account.withdraw(150.0);
    ASSERT_FALSE(success);
    ASSERT_EQ(100.0, account.getBalance());
}

TEST(AccountTest, WithdrawInvalidAmount) {
    Account account("12345", 100.0);
    ASSERT_THROW(account.withdraw(-50.0), std::invalid_argument);
    ASSERT_THROW(account.withdraw(0.0), std::invalid_argument);
}
