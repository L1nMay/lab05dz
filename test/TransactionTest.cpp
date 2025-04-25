#include "gtest/gtest.h"
#include "Transaction.h"

TEST(TransactionTest, ConstructorAndGetters) {
    Transaction transaction("12345", Transaction::Type::DEPOSIT, 100.0);
    ASSERT_EQ("12345", transaction.getAccountNumber());
    ASSERT_EQ(Transaction::Type::DEPOSIT, transaction.getType());
    ASSERT_EQ(100.0, transaction.getAmount());
}

TEST(TransactionTest, ConstructorAndGettersWithdraw) {
    Transaction transaction("54321", Transaction::Type::WITHDRAW, 50.0);
    ASSERT_EQ("54321", transaction.getAccountNumber());
    ASSERT_EQ(Transaction::Type::WITHDRAW, transaction.getType());
    ASSERT_EQ(50.0, transaction.getAmount());
}~
