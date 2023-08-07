#include "UserList.h"

#include <iostream>
#include <vector>
#include <algorithm>
//constructor
template <class H> UserList<H>::UserList()
{

}

//adds an item to the list
template <class H>
void UserList<H>::addToList(H *user)
{
    //only add a user if it is not already in the list
    if (find(list.begin(),list.end(),user)==list.end())
    {
        //user not found in list
        // so add it to the vector
        list.push_back(user);
    }
}

template <class H>
void UserList<H>::setUser(H *user)
{
    userType = user->getUserType();
}

template <class H> void UserList<H>::printList()
{
    if(userType == 1)
    {
        for (int i = 0; i < list.size(); i++)
        std::cout << "Name: " << list[i]->getName() << "\tAlias: " << list[i]->getAlias() << std::endl;
        
    }
    else
        std::cout << "You do not have permission to perform this action\n";
}
