//Holds info about a superuser
#include "User.h"

#define SUPERUSER_H
#ifdef SUPERUSER_H

class SuperUser: public User
{
public:
    SuperUser();
    SuperUser(string nm, string al, string pw);
    
    virtual void changeAlias();
};

#endif