#include "gtest/gtest.h" // Changed include
#include "Account.h"

TEST(AccountTest, InitialBalanceIsZero) {
    Account account;
    ASSERT_EQ(account.getBalance(), 0);
}

TEST(AccountTest, DepositIncreasesBalance) {
    Account account;
    account.deposit(100);
    ASSERT_EQ(account.getBalance(), 100);
}

TEST(AccountTest, WithdrawDecreasesBalance) {
    Account account;
    account.deposit(100);
    account.withdraw(50);
    ASSERT_EQ(account.getBalance(), 50);
}

TEST(AccountTest, WithdrawMoreThanBalanceFails) {
    Account account;
    ASSERT_FALSE(account.withdraw(100));
    ASSERT_EQ(account.getBalance(), 0);
}
