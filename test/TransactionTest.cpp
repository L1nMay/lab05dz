#include "gtest/gtest.h"
#include "Transaction.h"

TEST(TransactionTest, ConstructorAndGetters) {
    Transaction transaction("12345", Transaction::Type::DEPOSIT, 100.0);
    ASSERT_EQ("12345", transaction.getAccountNumber());
    ASSERT_EQ(Transaction::Type::DEPOSIT, transaction.getType());
    ASSERT_EQ(100.0, transaction.getAmount());
}
