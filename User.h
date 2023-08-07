//Holds info about a user
//
//
#include <iostream>
#ifndef USER_H
#define USER_H
using namespace std;

enum UserTypes{NORMAL, SUPERUSER};


class User
{
private:
    string Name;
    string Alias;
    string Password;
    int UserType{};


public:
    void setName(string nm);
    void setAlias(string alias);
    void setPassword(string pwd);
    void setUserType(int utype);
    
    //set to virtual so it can be redefined to let superuser change their aliases
    virtual void changeAlias();

    string getName() const;
    string getAlias() const;
    string getPassword() const;
    int getUserType() const;
    friend ostream& operator <<(ostream& outputStream, const User& user);

    User();
    User(string nm, string alias, string pwd);

};

#endif //USER_H
