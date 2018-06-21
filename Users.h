#ifndef USERS_H
#define USERS_H

#include <iostream>
#include "UsersFile.h"

using namespace std;

class Users{
private:
    UsersFile usersFile;
public:
    Users();
    virtual ~Users();

    void registration();
    int logIn();
    void logOut();
    void changePassword(int loggedUserId);

};

#endif
