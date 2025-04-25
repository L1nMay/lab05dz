#include "gtest/gtest.h"
#include "Account.h"

TEST(AccountTest, InitialBalanceIsZero) {
    Account account("testAccount", 0.0);
    ASSERT_EQ(account.getBalance(), 0);
}

TEST(AccountTest, DepositIncreasesBalance) {
    Account account("testAccount", 0.0);
    account.deposit(100);
    ASSERT_EQ(account.getBalance(), 100);
}

TEST(AccountTest, WithdrawDecreasesBalance) {
    Account account("testAccount", 0.0);
    account.deposit(100);
    account.withdraw(50);
    ASSERT_EQ(account.getBalance(), 50);
}

TEST(AccountTest, WithdrawMoreThanBalanceFails) {
    Account account("testAccount", 0.0);
    ASSERT_FALSE(account.withdraw(100));
    ASSERT_EQ(account.getBalance(), 0);
}
