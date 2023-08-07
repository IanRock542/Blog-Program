#ifndef AREA_H
#define AREA_H

#include <iostream>
#include <vector>
#include "Post.h"
#include "User.h"

class Area
{
public:
    //returns Description of Area
    std::string getDescription() const;


    void setDescription(std::string descrip);

    // return the name of the Area
    std::string getName() const;

    //set the name of the Area
    void setName(std::string nm);

    // return the index of the last post
    int getIndxLastPost() const;

    // add post
    int AddPost(const Post& p);

    // get post
    bool getPost(int i, Post &p);

    void copyPost(int i, Post &p);

    //overloads << for Area class
    friend std::ostream& operator <<(std::ostream& outputStream, const Area& area);

    void DeletePost(int i);

    void setUser(User u );

    bool checkEmpty();

    std::string getUsername() const;
    
    int getUType() const;

private:
    std::string Description; //description of Area
    std::string Name; //name of Area
    std::vector<Post> Posts;//vector of posts
    User user;

};

#endif //AREA_H