#ifndef AMOUNTCONVERTION_H
#define AMOUNTCONVERTION_H

#include <iostream>

using namespace std;

class AmountConvertion{
private:
    string strAmount;
    double amount;

    string changeComaToDot(string strAmount);
    bool doesItContainDotsAndDigits(string strAmount);
    bool isCorrectAmount(string strAmount);

public:
    AmountConvertion();
    virtual ~AmountConvertion();

    double enterAmount();
    string convertDoubleToString(double amount);
    double convertStringToDouble(string strAmount);
};

#endif
