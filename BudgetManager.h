#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>
#include "Date.h"
#include "Incomes.h"
#include "Expenses.h"

using namespace std;

class BudgetManager {
private:
    int loggedUserId;
    Date date;
    Incomes *incomes;
    Expenses *expenses;
    vector<Income> selectedIncomes;
    vector<Expense> selectedExpenses;

public:
    BudgetManager(int loggedUserId);
    virtual ~BudgetManager();

    void addIncome();
    void addExpense();

    void showBalanceFromSelectedPeriod();
    void showBalanceFromCurrentMonth();
    void showBalanceFromLastMonth();

private:
    void showBalance(int startDate, int endDate);
};

#endif
