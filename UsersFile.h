#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include "User.h"

using namespace std;

class UsersFile{
private:
    string fileName = "Users.xml";
public:
    int getLastUserId();
    bool doesUserExist(string login);
    void addUserToFile(User user);
    string getFileName();

};
#endif
