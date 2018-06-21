#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income{
private:
    int incomeId, userId, date;
    string item;
    double amount;

public:
    Income();
    virtual ~Income();

    int getIncomeId();
    int getUserId();
    int getDate();
    string getItem();
    double getAmount();

    void setIncomeId(int incomeId);
    void setUserId(int userId);
    void setDate(int date);
    void setItem(string item);
    void setAmount(double amount);
};

#endif
