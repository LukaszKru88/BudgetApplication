#include <iostream>
#include <windows.h>
#include "BudgetManager.h"

using namespace std;

BudgetManager::BudgetManager(int loggedUserId) {
    this->loggedUserId = loggedUserId;
    incomes = new Incomes(loggedUserId);
    expenses = new Expenses(loggedUserId);
}

BudgetManager::~BudgetManager() {
    selectedIncomes.clear();
    selectedExpenses.clear();
}

void BudgetManager::addIncome() {
    incomes->addIncome();
}

void BudgetManager::addExpense() {
    expenses->addExpense();
}

void BudgetManager::showBalanceFromCurrentMonth() {
    string strDate;
    int startDate = 0;
    int endDate = 0;
    strDate = date.getCurrentStringDate();
    startDate = date.getCurrentMonthStartIntDate(strDate);

    strDate = date.getCurrentStringDate();
    endDate = date.getCurrentIntDate(strDate);

    system("cls");
    cout << " >>> WYSWIETLANIE PRZYCHODU ZA BIEZACY MIESIAC <<<" << endl << endl;

    showBalance(startDate, endDate);
}

void BudgetManager::showBalanceFromSelectedPeriod() {
    int startDate = 0;
    int endDate = 0;

    do {
        system("cls");
        cout << " >>> WYSWIETLANIE PRZYCHODU ZA WYBRANY OKRES <<<" << endl << endl;
        cout << " >>> Data poczatkowa <<< " << endl;
        startDate = date.getDateFromUser();
        cout << endl;
        cout << " >>> Data koncowa <<< " << endl;
        endDate = date.getDateFromUser();
        cout << endl;

        if(startDate <= endDate) {
            showBalance(startDate, endDate);
        } else {
            cout << "Podana data poczatkowa jest wieksza od daty koncowej. Sproboj jeszcze raz" << endl;
            Sleep(2500);
        }
    } while(startDate > endDate);
}

void BudgetManager::showBalanceFromLastMonth() {
    string strDate;
    int startDate = 0;
    int endDate = 0;

    system("cls");
    cout << " >>> WYSWIETLANIE PRZYCHODU ZA POPRZEDNI MIESIAC <<<" << endl << endl;
    strDate = date.getCurrentStringDate();
    startDate = date.getLastMonthStartIntDate(strDate);

    strDate = date.getCurrentStringDate();
    endDate = date.getLastMonthEndIntDate(strDate);

    showBalance(startDate, endDate);
}

void BudgetManager::showBalance(int startDate, int endDate) {
    double incomesSum = 0.0d;
    double expensesSum = 0.0d;

    selectedIncomes = incomes->getIncomesFromSelectedPeriod(startDate, endDate);
    selectedExpenses = expenses->getExpensesFromSelectedPeriod(startDate, endDate);

    incomesSum = incomes->getIncomesSum(selectedIncomes);
    expensesSum = expenses->getExpensesSum(selectedExpenses);

    cout << "     >>> PRZYCHODY <<< " << endl << endl;
    incomes->showSelectedIncomes(selectedIncomes);
    cout << "SUMA PRZYCHODOW: " << incomesSum << endl;

    cout << endl << "     >>> WYDATKI <<< " << endl << endl;
    expenses->showSelectedExpenses(selectedExpenses);
    cout << "SUMA WYDATKOW: " << expensesSum << endl;

    cout << endl << " >>> ROZNICA PRZYCHODY - WYDATKI <<< " << endl;
    cout << incomesSum << " - " << expensesSum << " = " << incomesSum - expensesSum << endl << endl;
    system("pause");

}
