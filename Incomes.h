#ifndef INCOMES_H
#define INCOMES_H

#include <iostream>
#include <vector>
#include "Date.h"
#include "Income.h"
#include "IncomesFile.h"
#include "AmountConvertion.h"

using namespace std;

class Incomes{
private:
    int loggedUserId;
    vector<Income> incomes;
    IncomesFile incomesFile;
    AmountConvertion amountConvertion;
    //void sortIncomesByDateInAscendingOrder(vector<Income> &selectedIncomes);
    int lastIncomeId;
    Date date;

public:
    Incomes(int loggedUserId);
    virtual ~Incomes();

    void addIncome();
    vector<Income> getIncomesFromSelectedPeriod(int startDate, int endDate);
    void showSelectedIncomes(vector<Income> &selectedIncomes);
    double getIncomesSum(vector<Income> &selectedIncomes);
};

#endif
