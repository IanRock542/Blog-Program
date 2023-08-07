//Holds info about a user
//
//
#include <iostream>
#ifndef USER_H
#define USER_H

enum UserTypes{NORMAL, SUPERUSER};


class User
{
private:
    std::string Name;
    std::string Alias;
    std::string Password;
    int UserType{};


public:
    void setName(std::string nm);
    void setAlias(std::string alias);
    void setPassword(std::string pwd);
    void setUserType(int utype);
    
    //set to virtual so it can be redefined to let superuser change their aliases
    virtual void changeAlias();

    std::string getName() const;
    std::string getAlias() const;
    std::string getPassword() const;
    int getUserType() const;
    friend std::ostream& operator <<(std::ostream& outputStream, const User& user);

    User();
    User(std::string nm, std::string alias, std::string pwd);

};

#endif //USER_H
