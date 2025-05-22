#include "gtest/gtest.h"
#include "Transaction.h"
#include "MockAccount.h"
#include <gmock/gmock.h>

using ::testing::Return;
using ::testing::_;

TEST(TransactionTest, ConstructorAndGetters) {
    Transaction transaction("12345", Transaction::Type::DEPOSIT, 100.0);
    ASSERT_EQ("12345", transaction.getAccountNumber());
    ASSERT_EQ(Transaction::Type::DEPOSIT, transaction.getType());
    ASSERT_EQ(100.0, transaction.getAmount());
}

TEST(TransactionTest, MockAccountDepositTest) {
    MockAccount mockAccount;

    EXPECT_CALL(mockAccount, deposit(100.0))
        .Times(1)
        .WillOnce(Return(true));

    bool result = mockAccount.deposit(100.0);
    ASSERT_TRUE(result);
}

TEST(TransactionTest, MockAccountWithdrawTest) {
    MockAccount mockAccount;

    EXPECT_CALL(mockAccount, getBalance())
        .WillOnce(Return(150.0));

    EXPECT_CALL(mockAccount, withdraw(50.0))
        .Times(1)
        .WillOnce(Return(true));

    ASSERT_EQ(150.0, mockAccount.getBalance());
    bool result = mockAccount.withdraw(50.0);
    ASSERT_TRUE(result);
}

TEST(TransactionTest, MockAccountWithdrawFailsWhenInsufficientFunds) {
    MockAccount mockAccount;

    EXPECT_CALL(mockAccount, getBalance())
        .WillOnce(Return(30.0));

    EXPECT_CALL(mockAccount, withdraw(50.0))
        .Times(1)
        .WillOnce(Return(false));

    ASSERT_EQ(30.0, mockAccount.getBalance());
    bool result = mockAccount.withdraw(50.0);
    ASSERT_FALSE(result);
}
