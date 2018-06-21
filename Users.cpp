#include <iostream>
#include <windows.h>
#include "Markup.h"
#include "Users.h"
#include "User.h"
#include "UsersFile.h"

using namespace std;

Users::Users() {
    ;
}

Users::~Users() {
    ;
}

void Users::registration() {
    User user;
    int id = 0;
    string name, surname, login, password;

    system("cls");
    cout << ">>> REJESTROWANIE NOWEGO UZYTKOWNIKA <<<" << endl;

    id = usersFile.getLastUserId();
    user.setId(id);

    do {
        cout << endl << "Podaj login: ";
        cin >> login;
        cin.ignore();
    } while(usersFile.doesUserExist(login) == true);
    user.setLogin(login);

    cout << "Podaj haslo (minimum 3 znaki): ";
    cin >> password;
    cin.ignore();
    user.setPassword(password);

    cout << "Podaj imie: ";
    cin >> name;
    cin.ignore();
    user.setName(name);

    cout << "Podaj nazwisko: ";
    cin >> surname;
    cin.ignore();
    user.setSurname(surname);

    usersFile.addUserToFile(user);
}

int Users::logIn() {
    int loggedUserId;
    CMarkup XMLfile;
    UsersFile usersFile;

    string fileName, login, tempLogin, password, tempPassword;

    fileName = usersFile.getFileName();
    XMLfile.Load(fileName);

    system("cls");
    cout << ">>> LOGOWANIE UZYTKOWNIKA <<<" << endl;
    cout << endl << "Podaj login: ";
    cin >> login;

    XMLfile.FindElem("users");
    XMLfile.IntoElem();
    while(1) {
        while(XMLfile.FindElem("user")) {
            XMLfile.IntoElem();
            XMLfile.FindElem( "login" );
            tempLogin = XMLfile.GetData();
            if(tempLogin == login) {
                for(int atempt = 0; atempt < 3; atempt++) {
                    cout << "Podaj haslo. Pozostalo Ci: " << 3 - atempt << " prob ";
                    cin >> password;
                    XMLfile.FindElem("password");
                    tempPassword = XMLfile.GetData();
                    if(tempPassword == password) {
                        cout << endl << "Zalogowales sie." << endl;
                        Sleep(1500);
                        XMLfile.ResetMainPos();
                        XMLfile.FindElem("userId");
                        loggedUserId = atoi(MCD_2PCSZ(XMLfile.GetData()));
                        return loggedUserId;
                    }
                }
                cout << endl;
                cout << "Podales 3 razy bledne haslo. Poczekaj 3 sekundy przed kolejna proba" << endl;
                Sleep(3000);
                XMLfile.OutOfElem();
                XMLfile.ResetMainPos();
            } else
                XMLfile.OutOfElem();
        }
        cout << endl;
        cout << "Nie ma uzytkownika z takim loginem. Sproboj jeszcze raz" << endl;
        Sleep(1500);
        return 0;
    }
}

void Users::changePassword(int loggedUserId) {
    CMarkup users;
    int i = 1, tempUserId;
    string newPassword, tempPassword;

    system("cls");
    cout << ">>> ZMIANA HASLA <<<" << endl;
    cout << endl << "Podaj nowe haslo: ";
    cin >> newPassword;

    users.Load("users.xml");

    users.FindElem("users");
    users.IntoElem();
    while(i == 1) {
        while(users.FindElem("user")) {
            users.IntoElem();

            users.FindElem("userId");
            tempUserId = atoi(MCD_2PCSZ(users.GetData()));
            if(tempUserId == loggedUserId) {
                users.FindElem("password");
                users.RemoveElem();
                users.AddElem("password", newPassword);
            }
            users.OutOfElem();
        }
        users.Save("users.xml");
        i = 0;
    }
    cout << "Haslo zostalo zmienione" << endl;
    Sleep(1500);
}

