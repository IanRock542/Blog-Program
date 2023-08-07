#include <iostream>
#include <algorithm>
using namespace std;
#include "Post.h"


//Constructors
Post::Post(): options{0, 0, 0, 0}{ }

Post::Post(std::string m_title, std::string m_text, std::string m_user): options{0, 0, 0, 0}
{
    Title = m_title;
    Text = m_text;
    User = m_user;
}

//Destructor
Post::~Post()= default;

void Post::setTitle (std::string m_title)
{
    this->Title = m_title;
}

void Post::setText (std::string m_text)
{
    this->Text = m_text;
}

void Post::setUser (std::string m_user)
{
    this->User = m_user;
}

std::string Post::getTitle() const
{
    return this->Title;
}

std::string Post::getText() const
{
    return this->Text;
}

std::string Post::getUser() const
{
    return this->User;
}


void Post::addLove(const std::string& alias)
{
    this->options[0]++;

    // if user not found in list
    //adds it to the vector
    if (find(LikeAliases.begin(),LikeAliases.end(),alias)==LikeAliases.end())
        this->LoveAliases.push_back(alias);

}

void Post::addLike(const std::string& alias)
{
    this->options[1]++;
    
    if (find(LikeAliases.begin(),LikeAliases.end(),alias)==LikeAliases.end())
        LikeAliases.push_back(alias);
}

void Post::addDislike(const std::string& alias)
{
    this->options[2]++;
    
    if (find(DislikeAliases.begin(),DislikeAliases.end(),alias)==DislikeAliases.end())
        DislikeAliases.push_back(alias);
}

void Post::addHate(const std::string& alias)
{
    this->options[3]++;
    
    if (find(HateAliases.begin(),HateAliases.end(),alias)==HateAliases.end())
        HateAliases.push_back(alias);
}

int Post::getLove() const
{
    return this->options[0];
}

int Post::getLike() const
{
    return this->options[1];
}

int Post::getDislike() const
{
    return this->options[2];
}

int Post::getHate() const
{
    return this->options[3];
}

void Post::setLove(int love)
{
    this->options[0] = love;
}

void Post::setLike(int like)
{
    this->options[1] = like;
}

void Post::setDislike(int dislike)
{
    this->options[2] = dislike;
}

void Post::setHate(int hate)
{
    this->options[3] = hate;
}

//Overloads ==
bool operator ==(const Post& Post1, const Post& OtherPost)
{
    return (Post1.Title == OtherPost.Title);
}

ostream& operator <<(ostream& outputStream, const Post& p)
{
    std::cout << "Title:" << p.Title << std::endl;
    std::cout << "By:" << p.User << std::endl;
    std::cout << "Text:" << p.Text << std::endl;

    //checks if
    if((p.options[0] != 0) || (p.options[1] != 0) || (p.options[2] != 0) ||( p.options[3] != 0))
    {
        std::cout << "\nLoves: " << p.options[0] << " Likes: " << p.options[1] << std::endl;
        std::cout << "Dislikes: " << p.options[2] << " Hates: " << p.options[3] << std::endl;

        //checks if vector of users who have reacted is empty
        if(!p.LoveAliases.empty())
        {
            std::cout << "Loved by: " << std::endl;
            for (const auto &LoveAlias: p.LoveAliases)
                std::cout << LoveAlias << "\n\n";
        }

        if(!p.LikeAliases.empty())
        {
            std::cout << "Liked by: " << std::endl;
            for (const auto &LikeAlias: p.LikeAliases)
                std::cout << LikeAlias << "\n\n";
        }

        if(!p.DislikeAliases.empty())
        {
            std::cout << "Disliked by: " << std::endl;
            for (const auto &DislikeAlias: p.DislikeAliases)
                std::cout << DislikeAlias << "\n\n";
        }

        if(!p.HateAliases.empty())
        {
            std::cout << "Hated by: " << std::endl;
            for (const auto &HateAlias: p.HateAliases)
                std::cout << HateAlias << "\n\n";
        }
    }
    else
        std::cout << "No reactions to this post yet." << std::endl;

    return outputStream;
}


