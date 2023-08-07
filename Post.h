#include <iostream>
#include <vector>

#ifndef POST_H
#define POST_H

//class for Post
class Post
{
private:
    std::string Title;
    std::string Text;
    std::string User;
    int options[4];
    std::vector<std::string> LikeAliases;
    std::vector<std::string> LoveAliases;
    std::vector<std::string> HateAliases;
    std::vector<std::string> DislikeAliases;

public:
    void setTitle (std::string m_title);

    void setText (std::string m_text);

    void setUser (std::string m_user);

    std::string getTitle() const;

    std::string getText() const;

    std::string getUser() const;
    
    
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
    void addLove(const std::string& alias);
    void addLike(const std::string& alias);
    void addDislike(const std::string& alias);
    void addHate(const std::string& alias);

    //Overloads ==
    friend bool operator ==(const Post& Post1, const Post& OtherPost);

    //Constructors
    Post();

    Post(std::string m_title, std::string m_text, std::string m_user);

    //Destructor
    ~Post();

    //overloads << for Post class
    friend std::ostream& operator <<(std::ostream& outputStream, const Post& p);
    
    //adds user's alias to vector when they react to a post
    
};

#endif //POST_H