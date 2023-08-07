#ifndef AREA_H
#define AREA_H

#include <iostream>
#include <vector>
#include "Post.h"
#include "User.h"

using namespace std;




class Area
{
public:
    //returns Description of Area
    string getDescription() const;


    void setDescription(string descrip);

    // return the name of the Area
    string getName() const;

    //set the name of the Area
    void setName(string nm);

    // return the index of the last post
    int getIndxLastPost() const;

    // add post
    int AddPost(const Post& p);

    // get post
    bool getPost(int i, Post &p);

    void copyPost(int i, Post &p);

    //overloads << for Area class
    friend ostream& operator <<(ostream& outputStream, const Area& area);

    void DeletePost(int i);

    void setUser(User u );

    bool checkEmpty();

    string getUsername() const;
    
    int getUType() const;

private:
    string Description; //description of Area
    string Name; //name of Area
    vector<Post> Posts;//vector of posts
    User user;

};

#endif //AREA_H