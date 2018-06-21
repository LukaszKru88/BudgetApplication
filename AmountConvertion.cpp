#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
#include "AmountConvertion.h"

using namespace std;

AmountConvertion::AmountConvertion() {
    string strAmount = "";
    double amount = 0.0f;
}

AmountConvertion:: ~AmountConvertion() {
    ;
}

string AmountConvertion::changeComaToDot(string strAmount) {
    if(strAmount.size() > 0) {
        for(int i = 0; i < strAmount.size(); i++) {
            if(strAmount[i] == ',') {
                strAmount[i] = '.';
            }
        }
    }
    return strAmount;
}

bool AmountConvertion::doesItContainDotsAndDigits(string strAmount) {
    int i = 0;
    while(i < strAmount.size()) {
        if((strAmount[i] >= '0' && strAmount[i] <= '9') || strAmount[i] == '.') {
            i++;
        } else {
            return 0;
        }
    }
    return 1;
}

bool AmountConvertion::isCorrectAmount(string strAmount) {
    int counter = 0;
    for(int i = 0; i < strAmount.size(); i++) {
        if(strAmount[i] == '.') {
            counter++;
        }
    }

    if(counter >= 0 && counter <= 1) {
        return 1;
    } else {
        return 0;
    }
}

double AmountConvertion::convertStringToDouble(string strAmount) {
    double convertedAmount;
    stringstream ss(strAmount);

    if ( !(ss >> convertedAmount) ) {
        convertedAmount = 0;
    }
    convertedAmount = roundf(convertedAmount * 100) / 100;

    return convertedAmount;
}

double AmountConvertion::enterAmount() {
    while(1) {
        while(1) {

            cout << "Podaj wartosc: ";
            cin >> strAmount;

            if(strAmount == "0") {
                cout << endl << "Wartosc musi byc wieksza od zera. Sproboj jeszcze raz" << endl;
            } else {
                break;
            }
        }

        strAmount = changeComaToDot(strAmount);

        if(doesItContainDotsAndDigits(strAmount) == true && isCorrectAmount(strAmount) == true) {
            amount = convertStringToDouble(strAmount);
            return amount;
        } else {
            cout << endl << "Podany ciag znakow nie jest liczba. Podaj liczbe jeszcze raz" << endl << endl;
        }
    }
}

string AmountConvertion::convertDoubleToString(double amount) {
    ostringstream oss;
    oss << amount;
    return oss.str();
}
