#include <iostream>
#include <windows.h>
#include "Incomes.h"
#include "BudgetManager.h"

using namespace std;

Incomes::Incomes(int loggedUserId) {
    if(loggedUserId == 0) {
        exit(0);
    } else {
        this->loggedUserId = loggedUserId;
    }
    lastIncomeId = incomesFile.loadAllUserIncomes(incomes, loggedUserId);
}

Incomes::~Incomes() {
    incomes.clear();
}

void Incomes::addIncome() {
    Income income;
    Date date;

    string item;
    string amount;
    char selection;

    income.setIncomeId(++lastIncomeId);

    income.setUserId(loggedUserId);

    system("cls");
    cout << ">>> DODAWANIE PRZYCHODU <<<" << endl;
    cout << "Rozmiar vectora: "<< incomes.size() << endl;

    while(1) {
        cout << endl << "Podaj nazwe przychodu: ";
        cin.sync();
        getline(cin,item);

        if(item.length() == 0) {
            cout << endl;
            cout << "!!! Nie podales nazyw przychodu !!!" << endl;
            cout << "Aby przejsc dalej nalezy podac nazwe przychodu" << endl;
        } else {
            income.setItem(item);
            break;
        }
    }

    cout << endl << "Czy chcesz dodac przychod z dzisiejsza data? (t/n)" << endl;
    cout << "Wybor: ";
    cin >> selection;
    switch(selection) {
    case 't':
        income.setDate(date.getCurrentIntDate(date.getCurrentStringDate()));
        break;
    case 'n':
        income.setDate(date.getDateFromUser());
        break;
    }

    income.setAmount(amountConvertion.enterAmount());

    incomes.push_back(income);
    incomesFile.addIncomeToFile(income);

    cout << endl << "Przychod zostal dodany" << endl;
    system("pause");
}

vector<Income> Incomes::getIncomesFromSelectedPeriod(int startDate, int endDate) {
    vector<Income> selectedIncomes;

    if (!incomes.empty()) {
        for (vector<Income>::iterator itr = incomes.begin(); itr != incomes.end(); itr++) {
            if (itr->Income::getDate() >= startDate && itr->Income::getDate() <= endDate) {
                selectedIncomes.push_back(*itr);
            }
        }
    }
    return selectedIncomes;
}

void Incomes::showSelectedIncomes(vector<Income> &selectedIncomes) {
    if (!selectedIncomes.empty()) {
        // sortIncomesByDateInAscendingOrder(selectedIncomes);

        for (vector<Income>::iterator itr = selectedIncomes.begin(); itr != selectedIncomes.end(); itr++) {
            cout << "Date:      " << itr->Income::getDate() << endl;
            cout << "Item:      " << itr->Income::getItem() << endl;
            cout << "Amount:    " << itr->Income::getAmount() << endl << endl;
        }
    } else
        cout << endl << "Nie masz przychodow w wybranym zakresie czasu." << endl << endl;
}

double Incomes::getIncomesSum(vector<Income> &selectedIncomes) {
    double incomesSum = 0.0d;

    if (!selectedIncomes.empty()) {
        for (vector<Income>::iterator itr = selectedIncomes.begin(); itr != selectedIncomes.end(); itr++) {
            incomesSum = incomesSum  + itr->Income::getAmount();
        }
        return incomesSum;
    } else
        return 0;
}
