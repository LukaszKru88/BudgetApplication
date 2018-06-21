#include <iostream>
#include <windows.h>
#include "Users.h"
#include "Incomes.h"
#include "Date.h"
#include "BudgetManager.h"

using namespace std;

int main() {
    Users users;
    int loggedUserId = 0;
    char selection;

    while(true) {
        if(loggedUserId == 0) {
            system("cls");
            cout << " >>> APLIKACJA BUDZETOWA <<<" << endl << endl;
            cout << "ID ZALOGOWANEGO UZYTKOWNIKA: " << loggedUserId << endl << endl;
            cout << "1. Rejestracja" << endl;
            cout << "2. Logowanie" << endl;
            cout << "9. Zakoncz program" << endl;
            cout << endl << "Wybor: ";
            cin >> selection;

            switch (selection) {
            case '1':
                users.registration();
                break;
            case '2':
                loggedUserId = users.logIn();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        } else if(loggedUserId > 0) {
            BudgetManager budgetManager(loggedUserId);

            do {
                system("cls");
                cout << " >>> APLIKACJA BUDZETOWA <<<" << endl << endl;
                cout << "ID ZALOGOWANEGO UZYTKOWNIKA: " << loggedUserId << endl << endl;
                cout << " >>> PRZYCHODY I WYDATKI<<< " << endl;
                cout << "1. Dodaj przychod" << endl;
                cout << "2. Dodaj wydatek" << endl;
                cout << "3. Wyswietl bilans" << endl;

                cout << endl << " >>> OBSLOGA UZYTKOWNIKA <<< " << endl;
                cout << "7. Zmiana hasla" << endl;
                cout << "8. Wylogowanie" << endl;
                cout << "9. Zakoncz program" << endl;
                cout << endl << "Wybor: ";
                cin >> selection;

                switch (selection) {
                case '1':
                    budgetManager.addIncome();
                    break;
                case '2':
                    budgetManager.addExpense();
                    break;
                case '3':
                    system("cls");
                    cout << " >>> BILANSE OKRESOWE <<< " << endl << endl;
                    cout << "1. Wyswietl bilans za biezacy miesiac" << endl;
                    cout << "2. Wyswietl bilans za poprzedni miesiac" << endl;
                    cout << "3. Wyswietl bilans za wybrany okres" << endl;
                    cout << endl << "Wybor: ";
                    cin >> selection;

                    switch (selection) {
                    case '1':
                        budgetManager.showBalanceFromCurrentMonth();
                        break;
                    case '2':
                        budgetManager.showBalanceFromLastMonth();
                        break;
                    case '3':
                        budgetManager.showBalanceFromSelectedPeriod();
                        break;
                    }
                    break;
                case '7':
                    users.changePassword(loggedUserId);
                    break;
                case '8':
                    loggedUserId = 0;
                    break;
                case '9':
                    exit(0);
                    break;
                }
            } while(selection != '8');
        }
    }
    return 0;
}

