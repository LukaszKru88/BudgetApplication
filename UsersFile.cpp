#include <iostream>
#include <windows.h>
#include "Markup.h"
#include "UsersFile.h"

using namespace std;

string UsersFile::getFileName() {
    return fileName;
}

int UsersFile::getLastUserId() {
    int userId = 0;
    CMarkup XMLfile;
    if(!XMLfile.Load(fileName)) {
        return 1;
    } else {
        XMLfile.FindElem("users");
        XMLfile.IntoElem();

        while(XMLfile.FindElem("user")) {
            XMLfile.IntoElem();
            XMLfile.FindElem("userId");
            userId = atoi( MCD_2PCSZ(XMLfile.GetData()));
            XMLfile.OutOfElem();
        }
        return ++userId;
    }
}

bool UsersFile::doesUserExist(string login) {
    CMarkup XMLfile;
    if(XMLfile.Load(fileName)) {
        if(XMLfile.FindElem("users")) {
            XMLfile.IntoElem();
            while(XMLfile.FindElem("user")) {
                XMLfile.IntoElem();
                XMLfile.FindElem("login");
                if(XMLfile.GetData() == login) {
                    cout << "Podany login istnieje w bazie. Nalezy podac inny login" << endl;
                    Sleep(2500);
                    system("cls");
                    return 1;
                }
                XMLfile.OutOfElem();
            }
            return 0;
        }
    }
    return 0;
}

void UsersFile::addUserToFile(User user) {
    CMarkup XMLfile;
    XMLfile.Load(fileName);
    if(!XMLfile.FindElem("users")) {
        XMLfile.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        XMLfile.AddElem("users");
    }

    XMLfile.IntoElem();
    XMLfile.AddElem( "user");
    XMLfile.IntoElem();
    XMLfile.AddElem( "userId", user.getId());
    XMLfile.AddElem( "login", user.getLogin());
    XMLfile.AddElem( "password", user.getPassword());
    XMLfile.AddElem( "name", user.getName());
    XMLfile.AddElem( "surname", user.getSurname());
    XMLfile.OutOfElem();

    XMLfile.Save(fileName);
}



