#ifndef EXPENSES_H
#define EXPENSES_H

#include <iostream>
#include <vector>
#include "Date.h"
#include "Expense.h"
#include "ExpensesFile.h"
#include "AmountConvertion.h"

using namespace std;

class Expenses{
private:
    int loggedUserId;
    vector<Expense> expenses;
    ExpensesFile expensesFile;
    AmountConvertion amountConvertion;
    //void sortExpensesByDateInAscendingOrder(vector<Expense> &selectedExpenses);
    int lastExpenseId;
    Date date;

public:
    Expenses(int loggedUserId);
    virtual ~Expenses();

    void addExpense();
    vector<Expense> getExpensesFromSelectedPeriod(int startDate, int endDate);
    void showSelectedExpenses(vector<Expense> &selectedExpenses);
    double getExpensesSum(vector<Expense> &selectedExpenses);
};

#endif

