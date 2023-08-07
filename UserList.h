//template class //template 
#include <vector>
#include "User.h"

#ifndef USER_LIST_H
#define USER_LIST_H

template <class H>
class UserList
{
public:
    UserList();
    
    //add user to list
    void addToList(H* user);
    
    //set user type for printList function
    void setUser(H* user);
    
    //prints all user in list.
    void printList();
    
private:
    std::vector<H *> list;
    int userType;
};
#endif
