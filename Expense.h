#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

using namespace std;

class Expense{
private:
    int expenseId, userId, date;
    string item;
    double amount;

public:
    Expense();
    virtual ~Expense();

    int getExpenseId();
    int getUserId();
    int getDate();
    string getItem();
    double getAmount();

    void setExpenseId(int expenseId);
    void setUserId(int userId);
    void setDate(int date);
    void setItem(string item);
    void setAmount(double amount);
};

#endif
