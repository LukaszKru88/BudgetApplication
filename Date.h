#ifndef DATE_H
#define DATE_H

#include <iostream>

using namespace std;

class Date{
private:
    bool isLeapYear(unsigned short year);
    bool validDate(string date);
    bool checkingDate(unsigned short year,unsigned short month,unsigned short day);
    int changingDateFormatFromStringToInt(string date);
    string yearConvertionIntToString(int digit);
    string monthConvertionIntToString(int digit);
    string dayConvertionIntToString(int digit);

public:
    Date();
    virtual ~Date();

    string getCurrentStringDate();
    int getCurrentIntDate(string currentDate);
    int getCurrentMonthStartIntDate(string currentDate);
    int getLastMonthStartIntDate(string currentDate);
    int getLastMonthEndIntDate(string currentDate);
    int getDateFromUser();

};

#endif
