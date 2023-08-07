#include <iostream>
#include <vector>
#include <fstream>
#include "Area.h"
#include "Superuser.h"

#include "UserList.h"
#include "UserList.cpp"

/* Name: Ian Rockette Date: 10/26/2022 Section: 0011
Assignment: Module 9: Blog Program - Part 9 Due Date: 10/26/2022
About this project: This program lets the user select options from a menu to view, add, delete, or edit posts on a blog.
Using templates to take generic types.
Assumptions: assumes correct user input. All work below was performed by Ian Rockette */

//display menu
void displayMenu();

//User selects an action
void promptAction(std::string &strCh);

//implement Action
template <class T>
void implementAction(std::vector<Area> *areas, const std::string& strCh, T *u, UserList<User> *uList );

void DisplayBlogAreas(std::vector<Area> areas);

void DisplayPostsABlog(Area a);

//Displays a single blog
void DisplayOneBlogPost(std::vector<Area> areas);

//get a valid std::string max chars
std::string getValidString(int maxChars);

//get a valid blog area id
int getValidBlogArea();

//Lets user add their own post to a blog
Post userAddPost(std::vector<Area> &areas, int);

//lets user edit a blog post
void editPost(std::vector<Area> &areas);

//compares titles
bool compareTitles(const Post& p, Area area);

void deletePost(std::vector<Area> &areas);

void saveData(std::vector <Area> areas);
void readData(std::vector <Area> &areas);

template <class T>
int login(std::vector<T*> u, std::vector <Area> &areas);

void reactToPost(std::vector<Area> &areas);
void deleteArea(std::vector<Area> &areas);

template <class T>
void changeAlias(T *u, std::vector<Area> &areas);

//transfer user vector data to UserList
template <class T>
void ListTransfer(std::vector<T*> user, UserList<User> *uList);

int main()
{

    
    std::vector<Area> areas(5);

    std::vector<Area> * areas_ptr = &areas;
    std::vector<User> users;
    std::vector<User*> user_ptr;
    SuperUser ian{"Ian", "ir22", "lol"};
    user_ptr.push_back(&ian);
    User bob{"Bob", "bobby", "bleh"};
    user_ptr.push_back(&bob);

    User joe{"Joe", "joe_blow", "bing"};
    user_ptr.push_back(&joe);
    User ben{"Ben", "ben_money", "bang"};
    user_ptr.push_back(&ben);
    User jen{"Jenny", "jen213", "boom"};
    user_ptr.push_back(&jen);
    User fred{"Fred", "freddy", "oof"};
    user_ptr.push_back(&fred);
    
    UserList <User> uList;
    ListTransfer(user_ptr, &uList);
    std::cout << "Welcome to my Blog " << std::endl;

    std::string UserAction;
    int userIndex = login(user_ptr, *areas_ptr);
    
    //sets userType for print function
    uList.setUser(user_ptr[userIndex]);

    //initialize areas
    readData(*areas_ptr);

    do
    {
        promptAction(UserAction);
        implementAction(areas_ptr, UserAction, user_ptr[userIndex], &uList);

    } while ((UserAction != "Q") && (UserAction != "q"));
    //continue until user decides to quit


    return 0;
}



//display menu
void displayMenu()
{
    // display menu options to user
    std::cout << "Please select from the following options..." << std::endl;
    std::cout << " A  - Display Blog areas" << std::endl;
    std::cout << " B  - Display all posts for a blog" << std::endl;
    std::cout << " C  - Add a post to a blog" << std::endl;
    std::cout << " D  - Display a post for a blog" << std::endl;
    std::cout << " E  - Edit a post for a blog" << std::endl;
    std::cout << " F  - Delete a post for a blog" << std::endl;
    std::cout << " G  - Love/Like/Dislike/Hate a post" << std::endl;
    std::cout << " X  - Delete an Area" << std::endl;
    std::cout << " S  - Change an your Alias" << std::endl;
    std::cout << " Z  - Display all users" << std::endl;
    std::cout << " Q  - Quit\n\n";

}

//User Action
void promptAction(std::string &strCh)
{
    //display menu options to screen
    displayMenu();

    //prompt user for choice
    std::cout << "What would you like to do?\n";
    std::cin >> strCh;

}

//implement User's Action
template <class T>
void implementAction(std::vector<Area> *areas, const std::string& strCh, T *u, UserList<User> *uList)
{
    Post p;

    // if user selected A
    if ((strCh == "A") || (strCh == "a"))
    {
        DisplayBlogAreas(*areas);
    }

        // if user selects B
    else if ((strCh == "B") || (strCh == "b"))
    {
        std::cout << "Display all posts for a blog..." << std::endl;
        int blogId = getValidBlogArea();
        DisplayPostsABlog(areas->at(blogId));

    }
        // if user selects C
    else if ((strCh == "C") || (strCh == "c"))
    {

        //user has wants to add a new post
        std::cout << "Adding a new post..." << std::endl;
        int blogId = getValidBlogArea();
        p = userAddPost(*areas, blogId);
        areas->at(blogId).AddPost(p);

    }

        //user selected Q
    else if ((strCh == "D") || (strCh == "d"))
    {
        DisplayOneBlogPost(*areas);
    }
    else if ((strCh == "Q") || (strCh == "q"))
    {
        saveData(*areas);
        //user has selected to quit
        std::cout << "Bye..." << std::endl;
    }
    else if ((strCh == "E") || (strCh == "e"))
    {
        editPost(*areas);
    }
    else if ((strCh == "F") || (strCh == "f"))
    {
        deletePost(*areas);
    }
    else if ((strCh == "G") || (strCh == "g"))
    {
        reactToPost(*areas);
    }
    else if ((strCh == "X") || (strCh == "x"))
    {
        deleteArea(*areas);
    }
    else if ((strCh == "S") || (strCh == "s"))
    {
        changeAlias(u, *areas);
    }
    else if ((strCh == "Z") || (strCh == "z"))
    {
        uList->printList();
    }
    else
    {
        //user has selected an invalid option
        std::cout << strCh << " is not a valid option." << std::endl;
    }
}


void DisplayBlogAreas(std::vector<Area> areas)
{
    std::cout << "Display Blog areas..." << std::endl;
    //user has selected to display blog areas
    for (int i = 0; i < areas.size(); i++)
    {
        std::cout << "Area Index:" << i << std::endl;
        std::cout << areas[i] << std::endl;
        std::cout << "******************" << std::endl;
    }
}

void DisplayPostsABlog(Area a)
{
    std::cout << "Posts for " << a.getName() << std::endl;

    //user has selected to display blog areas
    for (int i = 0; i <= a.getIndxLastPost(); i++)
    {
        Post p;
        bool found = a.getPost(i, p);
        if (found)
        {
            std::cout << "Post Index:" << i << std::endl;
            std::cout << p << std::endl;
            std::cout << "******************" << std::endl;
        }
    }

}

void DisplayOneBlogPost(std::vector<Area> areas)
{
    int areaIndex, blogIndex;
    areaIndex = getValidBlogArea();

    std::cout << "Please enter a valid post id for: " << areas[areaIndex].getName() << "\n";
    std::cin >> blogIndex;

    Post p;
    bool found = areas[areaIndex].getPost(blogIndex, p);
    while(!found)
    {
        std::cout << "Please enter a valid post id for: " << areas[areaIndex].getName() << "\n";
        std::cin >> blogIndex;
        found = areas[areaIndex].getPost(blogIndex, p);
    }

    std::cout << "Post Index:" << blogIndex << std::endl;
    std::cout << p << std::endl;
    std::cout << "******************" << std::endl;

}

int getValidBlogArea()
{
    int area;
    //prompt and read in Blog Area Index
    std::cout << "Please enter in a Blog Area Index" << std::endl;
    std::cin >> area;
    //input validation loop
    while ((area < 0) || (area >= 5))
    {
        std::cout << "Please enter in a Blog Area Index" << std::endl;
        std::cin >> area;
    }
    //return valid Blog Area Index
    return area;
}

Post userAddPost(std::vector<Area> &areas, int areaIndex)
{

    Post p;

    std::string Title;
    std::cin.ignore();
    do
    {
        std::cout << "Please enter in the title..." << std::endl;
        Title = getValidString(20);
        p.setTitle(Title);
    }while(!compareTitles(p, areas[areaIndex]));

    std::cout << "Please enter in the text..." << std::endl;
    std::string Text = getValidString(500);

    p.setTitle(Title);
    p.setText(Text);
    p.setUser(areas[areaIndex].getUsername());

    std::cout << "Post added successfully.\n";

    return p;
}

void editPost(std::vector<Area> &areas)
{
    int areaIndex, blogIndex;
    areaIndex = getValidBlogArea();

    if(areas[areaIndex].checkEmpty())
        std::cout << "This blog has no posts to edit." << std::endl;
    else
    {
        std::cout << "Please enter a valid post id for: " << areas[areaIndex].getName() << "\n";
        std::cin >> blogIndex;

        Post p;
        bool found = areas[areaIndex].getPost(blogIndex, p);

        while (!found)
        {
            std::cout << "Please enter a valid post id for: " << areas[areaIndex].getName() << "\n";
            std::cin >> blogIndex;
            found = areas[areaIndex].getPost(blogIndex, p);
        }

        std::cout << p << std::endl;

        std::string Title;
        std::cin.ignore();
        do
        {
            std::cout << "Please enter in the title..." << std::endl;
            Title = getValidString(20);
            p.setTitle(Title);
        } while (!compareTitles(p, areas[areaIndex]));
        std::cout << "Please enter in the text..." << std::endl;
        std::string Text = getValidString(500);

        p.setTitle(Title);
        p.setText(Text);
        p.setUser(areas[areaIndex].getUsername());
        areas[areaIndex].copyPost(blogIndex, p);
        std::cout << "Post Edited" << std::endl;
    }

}

void deletePost(std::vector<Area> &areas)
{
    int areaIndex, blogIndex;
    areaIndex = getValidBlogArea();


    if(areas[areaIndex].checkEmpty())
        std::cout << "This blog has no posts." << std::endl;
    else
    {
        std::cout << "Please enter a valid post id for: " << areas[areaIndex].getName() << "\n";
        std::cin >> blogIndex;
        Post p;

        bool found = areas[areaIndex].getPost(blogIndex, p);
        while(!found)
        {
            std::cout << "Please enter a valid post id for: " << areas[areaIndex].getName() << "\n";
            std::cin >> blogIndex;
            found = areas[areaIndex].getPost(blogIndex, p);
        }
        areas[areaIndex].DeletePost(blogIndex);
        std::cout << "Post Index:" << blogIndex << " deleted."<< std::endl;

    }

}

const std::string WHITESPACE = " \n\r\t\f\v";

std::string ltrim(const std::string &s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}

std::string rtrim(const std::string &s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

std::string trim(const std::string &s)
{
    return rtrim(ltrim(s));
}

std::string getValidString(int maxChars)
{
    std::string text;
    do {
        std::cout << "Please enter in a string with at least 1 character and at most " << maxChars << " characters." << std::endl;
        getline(std::cin, text);
        text = trim(text);
    } while ((text.length() == 0) || (text.length() > maxChars));
    return text;
}

bool compareTitles(const Post& p, Area area)
{
    for (int i = 0; i <= area.getIndxLastPost(); i++)
    {
        Post p2;
        area.getPost(i, p2);
        if (p == p2)
        {
            std::cout << "Another post in this blog has this identical title" << std::endl;
            std::cout << "Please enter a new unique title" << std::endl;
            return false;
        }
    }
    return true;
}

void saveData(std::vector <Area> areas)
{
    std::ofstream outputFile("Areas.txt");
    std::ofstream outputFile2("Posts.txt");
    if(outputFile.fail())
    {
        std::cout<<"Error opening Areas.txt";
        exit(1);
    }
    outputFile << areas.size() << std::endl;

    for (int i=0;i < areas.size();i++)
    {
        outputFile<< areas[i].getName()<<std::endl;
        outputFile<< areas[i].getDescription()<<std::endl;
        outputFile << areas[i].getIndxLastPost() << std::endl;

        for (int j=0; j <= areas[i].getIndxLastPost();j++)
        {
            Post p;
            bool found = areas[i].getPost(j, p);
            if (found)
            {
                outputFile2 << p.getTitle() << std::endl;
                outputFile2 << p.getUser() << std::endl;
                outputFile2 << p.getText() << std::endl;
                outputFile2 << p.getLove() << std::endl;
                outputFile2 << p.getLike() << std::endl;
                outputFile2 << p.getDislike() << std::endl;
                outputFile2 << p.getHate() << std::endl;
            }
        }

    }
    outputFile.close();
    outputFile2.close();
}

void readData(std::vector <Area> &areas)
{
    std::ifstream areasFile("Areas.txt");
    std::ifstream postFile("Posts.txt");
    Post p;
    std::string blogTitle,descrip, title, user, text;
    int areaIndex, blogSize=0;

    if(areasFile.fail())
    {
        std::cout << "Error: Could not open Area file.";
        exit(1);
    }

    if(postFile.fail())
    {
        std::cout << "Error: Could not open Post file.";
        exit(1);
    }


    size_t size;
    areasFile >> size;
    areas.resize(size);

    areasFile.ignore();
    for(areaIndex=0; areaIndex < static_cast<int>(size); areaIndex++)
    {
        getline(areasFile, blogTitle);
        getline(areasFile, descrip);

        areasFile >> blogSize;
        areasFile.ignore();

        areas[areaIndex].setName(blogTitle);
        areas[areaIndex].setDescription(descrip);


        for (int i = 0; i < blogSize; i++)
        {
            int love, like, dislike, hate;
            getline(postFile, title);
            getline(postFile, user);
            getline(postFile, text);
            postFile >> love;
            postFile >> like;
            postFile >> dislike;
            postFile >> hate;
            postFile.ignore();

            p.setTitle(title);
            p.setUser(user);
            p.setText(text);
            p.setLove(love);
            p.setLike(like);
            p.setDislike(dislike);
            p.setHate(hate);

            areas[areaIndex].AddPost(p);
        }
    }
    areasFile.close();
    postFile.close();
}

template <class T>
int login(const std::vector<T*> users, std::vector <Area> &areas)
{
    std::string name, alias, pwd, enteredAlias, enteredPwd;
    bool comparison = false;
    int i;

    while(!comparison)
    {
        std::cout << "Enter your username/alias: ";
        getline(std::cin , enteredAlias);
        for(i = 0; i < users.size(); i++)
        {
            name = users[i]->getAlias();
            if(enteredAlias == name)
            {
                pwd = users[i]->getPassword();
                std::cout << "Enter your password: ";
                getline(std::cin, enteredPwd);
                while(enteredPwd != pwd)
                {
                    std::cout << "Enter your password: ";
                    getline(std::cin, enteredPwd);
                }

                std::cout << *users[i] << std::endl;
                for(auto & area : areas)
                    area.setUser(*users[i]);

                comparison = true;
                return i;
            }
        }
    }

    return 0;
}

void reactToPost(std::vector<Area> &areas)
{
    int areaIndex, blogIndex;
    areaIndex = getValidBlogArea();
    char choice;

    std::cout << "Please enter a valid post id for: " << areas[areaIndex].getName() << "\n";
    std::cin >> blogIndex;

    Post p;
    bool found = areas[areaIndex].getPost(blogIndex, p);
    while(!found)
    {
        std::cout << "Please enter a valid post id for: " << areas[areaIndex].getName() << "\n";
        std::cin >> blogIndex;
        found = areas[areaIndex].getPost(blogIndex, p);
    }

    std::cout << "Enter:\n";
    std::cout << "A to love the post." << std::endl;
    std::cout << "B to like the post." << std::endl;
    std::cout << "C to dislike the post." << std::endl;
    std::cout << "D to hate the post." << std::endl;

    std::cin >> choice;
    tolower(choice);


    if(choice=='a')
    {
        p.addLove(areas[areaIndex].getUsername());
        areas[areaIndex].copyPost(blogIndex, p);
    }
    else if(choice=='b')
    {
        p.addLike(areas[areaIndex].getUsername());
        areas[areaIndex].copyPost(blogIndex, p);
    }
    else if(choice=='c')
    {
        p.addDislike(areas[areaIndex].getUsername());
        areas[areaIndex].copyPost(blogIndex, p);
    }
    else if(choice=='d')
    {
        p.addHate(areas[areaIndex].getUsername());
        areas[areaIndex].copyPost(blogIndex, p);
    }
    else
        std::cout << "Invalid option" << std::endl;
}

void deleteArea(std::vector<Area> &areas)
{
    //checks user type to make sure that the user has permission to perform this action
    if(areas[0].getUType() != 1)
        std::cout << "You do not have permission to perform this action. Only Superusers can delete areas." << std::endl;
    else
    {
        int areaIndex = getValidBlogArea();
        for (int i = 0; i <= areas[areaIndex].getIndxLastPost(); i++)
        {
            Post p;
            bool found = areas[areaIndex].getPost(i, p);
            if (found)
                areas[areaIndex].DeletePost(i);
        }

        areas.erase(areas.begin()+areaIndex);
        size_t new_size = areas.size();
        areas.resize(new_size);

        std::cout << "Blog Index: " << areaIndex << " deleted" << std::endl;

    }
}

template <class T>
void changeAlias(T *u, std::vector<Area> &areas)
{
    u->changeAlias();
    //updates user info for all areas
    for(auto & area : areas)
        area.setUser(*u);
}

template <class T>
void ListTransfer(const std::vector<T*> user, UserList<User> *uList)
{
    for (int i = 0; i < user.size(); i++)
    {
        uList->addToList(user[i]);
        //std::cout << "Added user: " << user[i] << " to the list.\n";
    }
}
