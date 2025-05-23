#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <chrono>

class Transaction {
public:
    enum class Type {
        DEPOSIT,
        WITHDRAWAL,
        TRANSFER // Добавляем новый тип транзакции
    };

    Transaction(const std::string& accountNumber, Type type, double amount);

    std::string getAccountNumber() const;
    Type getType() const;
    double getAmount() const;
    std::chrono::system_clock::time_point getTimestamp() const;

private:
    std::string accountNumber;
    Type type;
    double amount;
    std::chrono::system_clock::time_point timestamp;
};

#endif
