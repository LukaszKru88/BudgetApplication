#ifndef EXPENSESFILE_H
#define EXPENSESFILE_H

#include <iostream>
#include <vector>
#include "Expense.h"
#include "AmountConvertion.h"

using namespace std;

class ExpensesFile{
private:
    string fileName = "Expenses.xml";
    AmountConvertion amountConvertion;

public:
    void addExpenseToFile(Expense expense);
    int loadAllUserExpenses(vector<Expense> &expenses, int loggedUserId);
    int getLastExpenseIdFromFile();

};

#endif
