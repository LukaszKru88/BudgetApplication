#include <iostream>
#include <windows.h>
#include "Expenses.h"
#include "BudgetManager.h"

using namespace std;

Expenses::Expenses(int loggedUserId) {
    if(loggedUserId == 0) {
        exit(0);
    } else {
        this->loggedUserId = loggedUserId;
    }
    lastExpenseId = expensesFile.loadAllUserExpenses(expenses, loggedUserId);
}

Expenses::~Expenses() {
    expenses.clear();
}

void Expenses::addExpense() {
    Expense expense;
    Date date;

    string item;
    string amount;
    char selection;

    expense.setExpenseId(++lastExpenseId);

    expense.setUserId(loggedUserId);

    system("cls");
    cout << ">>> DODAWANIE WYDATKU <<<" << endl;
    cout << "Rozmiar vectora: "<< expenses.size() << endl;

    while(1) {
        cout << endl << "Podaj nazwe wydatku: ";
        cin.sync();
        getline(cin,item);

        if(item.length() == 0) {
            cout << endl;
            cout << "!!! Nie podales nazyw wydatku !!!" << endl;
            cout << "Aby przejsc dalej nalezy podac nazwe wydatku" << endl;
        }else {
        expense.setItem(item);
        break;
        }
    }

    cout << endl << "Czy chcesz dodac wydatek z dzisiejsza data? (t/n)" << endl;
    cout << "Wybor: ";
    cin >> selection;
    switch(selection) {
    case 't':
        expense.setDate(date.getCurrentIntDate(date.getCurrentStringDate()));
        break;
    case 'n':
        expense.setDate(date.getDateFromUser());
        break;
    }

    expense.setAmount(amountConvertion.enterAmount());

    expenses.push_back(expense);
    expensesFile.addExpenseToFile(expense);

    cout << endl << "Wydatek zostal dodany" << endl;
    system("pause");
}

vector<Expense> Expenses::getExpensesFromSelectedPeriod(int startDate, int endDate) {
    vector<Expense> selectedExpenses;

    if (!expenses.empty()) {
        for (vector<Expense>::iterator itr = expenses.begin(); itr != expenses.end(); itr++) {
            if (itr->Expense::getDate() >= startDate && itr->Expense::getDate() <= endDate) {
                selectedExpenses.push_back(*itr);
            }
        }
    }
    return selectedExpenses;
}

void Expenses::showSelectedExpenses(vector<Expense> &selectedExpenses) {
    if (!selectedExpenses.empty()) {
        // sortIncomesByDateInAscendingOrder(selectedIncomes);

        for (vector<Expense>::iterator itr = selectedExpenses.begin(); itr != selectedExpenses.end(); itr++) {
            cout << "Date:      " << itr->Expense::getDate() << endl;
            cout << "Item:      " << itr->Expense::getItem() << endl;
            cout << "Amount:    " << itr->Expense::getAmount() << endl << endl;
        }
    } else
        cout << endl << "Nie masz wydatkow w wybranym zakresie czasu." << endl << endl;
}

double Expenses::getExpensesSum(vector<Expense> &selectedExpenses) {
    double expensesSum = 0.0d;

    if (!selectedExpenses.empty()) {
        for (vector<Expense>::iterator itr = selectedExpenses.begin(); itr != selectedExpenses.end(); itr++) {
            expensesSum = expensesSum  + itr->Expense::getAmount();
        }
        return expensesSum;
    } else
        return 0;
}
