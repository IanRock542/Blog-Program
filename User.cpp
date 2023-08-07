#include <iostream>
#include "User.h"

class Area;

void User::setName(string nm)
{
    Name = nm;
}
void User::setAlias(string alias)
{
    Alias = alias;
}
void User::setPassword(string pwd)
{
    Password = pwd;
}

void User::setUserType(int utype)
{
    UserType = utype;
}

string User::getName() const
{
    return this->Name;
}
string User::getAlias() const
{
    return this->Alias;
}
string User::getPassword() const
{
    return this->Password;
}

int User::getUserType() const
{
    return this->UserType;
}

User::User()
{
    this->setUserType(NORMAL);
}

User::User(string nm, string alias, string pwd):Name(nm), Alias(alias), Password(pwd)
{
    this->setUserType(NORMAL);
}

void User::changeAlias()
{
    cout << "You do not have permission to perform this action." << endl;
}



ostream& operator <<(ostream& outputStream, const User& user)
{
    if(user.UserType == 1)
        cout << "-----SUPER USER----"  << endl;
    cout << "Hello, "  << user.Name << endl;

    return outputStream;
}