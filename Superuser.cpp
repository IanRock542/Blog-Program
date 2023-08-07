#include "Superuser.h"

SuperUser::SuperUser()
{
    this->setUserType(SUPERUSER);
}

SuperUser::SuperUser(std::string nm, std::string al, std::string pw):User(nm, al, pw)
{
    this->setUserType(SUPERUSER);
}

//Only superusers can use this function
void SuperUser::changeAlias()
{
    std::string alias;
    std::cout << "Enter the new alias: " ;
    std::cin >> alias;
    this-> setAlias(alias);
}