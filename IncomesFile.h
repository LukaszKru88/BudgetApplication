#ifndef INCOMESFILE_H
#define INCOMESFILE_H

#include <iostream>
#include <vector>
#include "Income.h"
#include "AmountConvertion.h"

using namespace std;

class IncomesFile{
private:
    string fileName = "Incomes.xml";
    AmountConvertion amountConvertion;

public:
    void addIncomeToFile(Income income);
    int loadAllUserIncomes(vector<Income> &incomes, int loggedUserId);
    int getLastIncomeIdFromFile();

};


#endif
