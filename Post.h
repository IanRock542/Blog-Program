#include <iostream>
#include <vector>
using namespace std;

#ifndef POST_H
#define POST_H

//class for Post
class Post
{
private:
    string Title;
    string Text;
    string User;
    int options[4];
    vector<string> LikeAliases;
    vector<string> LoveAliases;
    vector<string> HateAliases;
    vector<string> DislikeAliases;

public:
    void setTitle (string m_title);

    void setText (string m_text);

    void setUser (string m_user);

    string getTitle() const;

    string getText() const;

    string getUser() const;
    
    
    //getter and set functions for reactions
    int getLove() const;
    int getLike() const;
    int getDislike() const;
    int getHate() const;
    
    void setLove(int love);
    void setLike(int like);
    void setDislike(int dislike);
    void setHate(int hate);
    
    //iterator functions for reactions
    void addLove(const string& alias);
    void addLike(const string& alias);
    void addDislike(const string& alias);
    void addHate(const string& alias);

    //Overloads ==
    friend bool operator ==(const Post& Post1, const Post& OtherPost);

    //Constructors
    Post();

    Post(string m_title, string m_text, string m_user);

    //Destructor
    ~Post();

    //overloads << for Post class
    friend ostream& operator <<(ostream& outputStream, const Post& p);
    
    //adds user's alias to vector when they react to a post
    
};

#endif //POST_H