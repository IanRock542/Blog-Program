#include <iostream>
#include "Area.h"

using namespace std;



string Area::getDescription() const
{
    return this->Description;
}


void Area::setDescription(string descrip)
{
    this->Description = descrip;
}

// return the name of the Area
string Area::getName() const
{
    return this->Name;
}

//set the name of the Area
void Area::setName(string nm)
{
    this->Name = nm;
}

// return the index of the last post
int Area::getIndxLastPost() const
{
    return this->Posts.size();
}

bool Area::getPost(int i, Post &p)
{
    if (i < Posts.size()) // i is valid
    {
        p = Posts[i]; //set post
        return true; //return true
    } else
    { //i is not valid
        return false; //return false
    }
}

void Area::copyPost(int i, Post &p) //overwrites a post
{
    this->Posts[i] = p;
}


int Area::AddPost(const Post& p)
{
    //validate that less than MAX_NUM_POSTS have been added
    // to this blog

    this->Posts.push_back(p);

    //return 1 - added
    return 1;
}

void Area::DeletePost(int i)
{
    this->Posts.erase(Posts.begin()+i);
    size_t size = Posts.size();
    this->Posts.resize(size);
}

bool Area::checkEmpty()
{
    if(Posts.empty())
        return true;
    else
        return false;
}

string Area::getUsername() const
{
    return this->user.getAlias();
}

void Area::setUser(User u)
{
    user = u;
}

int Area::getUType() const
{
    return this->user.getUserType();
}

ostream& operator <<(ostream& outputStream, const Area& area)
{
    cout << "Area Name:" << area.Name << endl;
    cout << "Description: " << area.Description << endl;

    return outputStream;
}