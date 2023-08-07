#include "Superuser.h"

SuperUser::SuperUser()
{
    this->setUserType(SUPERUSER);
}

SuperUser::SuperUser(string nm, string al, string pw):User(nm, al, pw)
{
    this->setUserType(SUPERUSER);
}

//Only superusers can use this function
void SuperUser::changeAlias()
{
    string alias;
    cout << "Enter the new alias: " ;
    cin >> alias;
    this-> setAlias(alias);
}