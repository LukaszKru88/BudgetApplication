#include <iostream>
#include <windows.h>
#include <sstream>
#include "Date.h"

using namespace std;

Date::Date() {
    SYSTEMTIME time;
    GetLocalTime(&time);
}

Date::~Date() {
    ;
}

int Date::changingDateFormatFromStringToInt(string date) {
    string tempLine, year, month, day;
    int changedDate;

    date += "-";
    int counter = 1;
    for(int i = 0; i <= date.size() + 1 ; i++) {
        if(date[i] != '-') {
            tempLine += date[i];
        } else {
            switch(counter) {
            case 1:
                year = tempLine;
                break;
            case 2:
                month = tempLine;
                break;
            case 3:
                day = tempLine;
                break;
            }
            tempLine = "";
            counter++;
        }
    }
    date = year + month + day;
    changedDate = atoi(date.c_str());
    return changedDate;
}

string Date::monthConvertionIntToString(int digit) {
    ostringstream ss;
    ss << digit;
    string str = ss.str();
    if(str >= "1" && str <= "9")
        str = '0' + str;
    return str;
}

string Date::dayConvertionIntToString(int digit) {
    ostringstream ss;
    ss << digit;
    string str = ss.str();
    if(str >= "9")
        str = '0' + str;
    return str;
}

string Date::yearConvertionIntToString(int digit) {
    ostringstream ss;
    ss << digit;
    string str = ss.str();
    return str;
}

string Date::getCurrentStringDate() {
    int year, month, day;
    string date, stYear, stMonth, stDay;

    SYSTEMTIME time;
    GetLocalTime(&time);

    year = time.wYear;
    month = time.wMonth;
    day = time.wDay;

    stYear = yearConvertionIntToString(year);
    stMonth = monthConvertionIntToString(month);
    stDay = dayConvertionIntToString(day);

    date = stYear + '-' + stMonth + '-' + stDay;
    return date;
}

int Date::getCurrentIntDate(string currentDate) {
    string tempLine, year, month, day;
    int changedDate;

    currentDate += "-";
    int counter = 1;
    for(int i = 0; i <= currentDate.size() + 1 ; i++) {
        if(currentDate[i] != '-') {
            tempLine += currentDate[i];
        } else {
            switch(counter) {
            case 1:
                year = tempLine;
                break;
            case 2:
                month = tempLine;
                break;
            case 3:
                day = tempLine;
                break;
            }
            tempLine = "";
            counter++;
        }
    }
    currentDate = year + month + day;
    changedDate = atoi(currentDate.c_str());
    return changedDate;
}

int Date::getCurrentMonthStartIntDate(string currentDate) {
    string tempLine = "", year = "", month = "", day = "";
    int changedDate = 0;

    currentDate += "-";
    int counter = 1;
    for(int i = 0; i <= currentDate.size() - 1 ; i++) {
        if(currentDate[i] != '-') {
            tempLine += currentDate[i];
        } else {
            switch(counter) {
            case 1:
                year = tempLine;
                break;
            case 2:
                month = tempLine;
                break;
            }
            tempLine = "";
            counter++;
        }
    }

    currentDate = year + month + "01";
    changedDate = atoi(currentDate.c_str());
    return changedDate;
}

int Date::getLastMonthStartIntDate(string currentDate) {
    string tempLine = "", year = "", month = "", day = "";
    int lastMonth = 0, lastYear = 0;
    int changedDate = 0;

    currentDate += "-";
    int counter = 1;
    for(int i = 0; i <= currentDate.size() - 1 ; i++) {
        if(currentDate[i] != '-') {
            tempLine += currentDate[i];
        } else {
            switch(counter) {
            case 1:
                year = tempLine;
                break;
            case 2:
                month = tempLine;
                break;
            }
            tempLine = "";
            counter++;
        }
    }

    lastMonth = atoi(month.c_str());
    lastMonth--;
    month = monthConvertionIntToString(lastMonth);

    if(lastMonth == 1) {
        lastYear = atoi(year.c_str());
        lastYear--;
        year = yearConvertionIntToString(lastYear);
    }

    currentDate = year + month + "01";
    changedDate = atoi(currentDate.c_str());
    return changedDate;
}

int Date::getLastMonthEndIntDate(string currentDate) {
    string tempLine = "", year = "", month = "", day = "";
    int lastMonth = 0, lastYear = 0;
    short unsigned int leapYear = 0;
    int changedDate = 0;

    currentDate += "-";
    int counter = 1;
    for(int i = 0; i <= currentDate.size() - 1 ; i++) {
        if(currentDate[i] != '-') {
            tempLine += currentDate[i];
        } else {
            switch(counter) {
            case 1:
                year = tempLine;
                break;
            case 2:
                month = tempLine;
                break;
            }
            tempLine = "";
            counter++;
        }
    }

    lastMonth = atoi(month.c_str());
    lastMonth--;
    month = monthConvertionIntToString(lastMonth);

    if(lastMonth == 1) {
        lastYear = atoi(year.c_str());
        lastYear--;
        year = yearConvertionIntToString(lastYear);
    }

    if(month == "01" || month == "03" || month == "05" || month == "07" || month == "08" || month == "10" || month == "12") {
        day = "31";
    } else if(month == "04" ||month == "06" ||month == "09" ||month == "11") {
        day = "30";
    } else if(month == "02") {
        leapYear = atoi(year.c_str());
        if(isLeapYear(leapYear)) {
            day = "29";
        } else day = "28";
    }

    currentDate = year + month + day;
    changedDate = atoi(currentDate.c_str());
    return changedDate;
}

int Date::getDateFromUser() {
    string date = "";
    int changedDate = 0;
    while(1) {
        cout << "Podaj date w formacie rrrr-mm-dd" << endl;
        cin >> date;

        if(validDate(date)) {
            cout << "Podana data jest prawidlowa" << endl;
            changedDate = changingDateFormatFromStringToInt(date);
            Sleep(1000);
            break;
        } else {
            cout << "Podana data jest nieprawidlowa. Sproboj jeszcze raz" << endl;
            Sleep(1000);
        }
    }
    return changedDate;
}

bool Date::validDate(string date) {

    unsigned short year, month, day;
    string tempLine;

    date += "-";
    int counter = 1;
    for(int i = 0; i <= date.size() + 1 ; i++) {
        if(date[i] != '-') {
            tempLine += date[i];
        } else {
            switch(counter) {
            case 1:
                year = atoi(tempLine.c_str());
                break;
            case 2:
                month = atoi(tempLine.c_str());
                break;
            case 3:
                day = atoi(tempLine.c_str());
                break;
            }
            tempLine = "";
            counter++;
        }
    }
    return checkingDate(year, month, day);
}

bool Date::checkingDate(unsigned short year,unsigned short month,unsigned short day) {
    unsigned short monthlen[]= {31,28,31,30,31,30,31,31,30,31,30,31};
    if (!year || !month || !day || month>12)
        return 0;
    if (isLeapYear(year) && month==2)
        monthlen[1]++;
    if (day>monthlen[month-1])
        return 0;
    return 1;
}

bool Date::isLeapYear(unsigned short year) {
    return (!(year%4) && (year%100) || !(year%400));
}


