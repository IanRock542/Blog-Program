#include <iostream>
#include "User.h"

class Area;

void User::setName(std::string nm)
{
    Name = nm;
}
void User::setAlias(std::string alias)
{
    Alias = alias;
}
void User::setPassword(std::string pwd)
{
    Password = pwd;
}

void User::setUserType(int utype)
{
    UserType = utype;
}

std::string User::getName() const
{
    return this->Name;
}
std::string User::getAlias() const
{
    return this->Alias;
}
std::string User::getPassword() const
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

User::User(std::string nm, std::string alias, std::string pwd):Name(nm), Alias(alias), Password(pwd)
{
    this->setUserType(NORMAL);
}

void User::changeAlias()
{
    std::cout << "You do not have permission to perform this action." << std::endl;
}



std::ostream& operator <<(std::ostream& outputStream, const User& user)
{
    if(user.UserType == 1)
        std::cout << "-----SUPER USER----"  << std::endl;
    std::cout << "Hello, "  << user.Name << std::endl;

    return outputStream;
}