#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User {
private:
    int id;
    string name, surname, login, password;

public:
    User();
    virtual ~User();

    int getId();
    string getName();
    string getSurname();
    string getLogin();
    string getPassword();

    void setId(int id);
    void setName(string name);
    void setSurname(string surname);
    void setLogin(string login);
    void setPassword(string password);
};

#endif
