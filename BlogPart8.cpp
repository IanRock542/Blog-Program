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


using namespace std;

//display menu
void displayMenu();

//User selects an action
void promptAction(string &strCh);

//implement Action
template <class T>
void implementAction(vector<Area> *areas, const string& strCh, T *u, UserList<User> *uList );

void DisplayBlogAreas(vector<Area> areas);

void DisplayPostsABlog(Area a);

//Displays a single blog
void DisplayOneBlogPost(vector<Area> areas);

//get a valid string max chars
string getValidString(int maxChars);

//get a valid blog area id
int getValidBlogArea();

//Lets user add their own post to a blog
Post userAddPost(vector<Area> &areas, int);

//lets user edit a blog post
void editPost(vector<Area> &areas);

//compares titles
bool compareTitles(const Post& p, Area area);

void deletePost(vector<Area> &areas);

void saveData(vector <Area> areas);
void readData(vector <Area> &areas);

template <class T>
int login(vector<T*> u, vector <Area> &areas);

void reactToPost(vector<Area> &areas);
void deleteArea(vector<Area> &areas);

template <class T>
void changeAlias(T *u, vector<Area> &areas);

//transfer user vector data to UserList
template <class T>
void ListTransfer(vector<T*> user, UserList<User> *uList);

int main()
{

    
    vector<Area> areas(5);

    vector<Area> * areas_ptr = &areas;
    vector<User> users;
    vector<User*> user_ptr;
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
    cout << "Welcome to my Blog " << endl;

    string UserAction;
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
    cout << "Please select from the following options..." << endl;
    cout << " A  - Display Blog areas" << endl;
    cout << " B  - Display all posts for a blog" << endl;
    cout << " C  - Add a post to a blog" << endl;
    cout << " D  - Display a post for a blog" << endl;
    cout << " E  - Edit a post for a blog" << endl;
    cout << " F  - Delete a post for a blog" << endl;
    cout << " G  - Love/Like/Dislike/Hate a post" << endl;
    cout << " X  - Delete an Area" << endl;
    cout << " S  - Change an your Alias" << endl;
    cout << " Z  - Display all users" << endl;
    cout << " Q  - Quit\n\n";

}

//User Action
void promptAction(string &strCh)
{
    //display menu options to screen
    displayMenu();

    //prompt user for choice
    cout << "What would you like to do?\n";
    cin >> strCh;

}

//implement User's Action
template <class T>
void implementAction(vector<Area> *areas, const string& strCh, T *u, UserList<User> *uList)
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
        cout << "Display all posts for a blog..." << endl;
        int blogId = getValidBlogArea();
        DisplayPostsABlog(areas->at(blogId));

    }
        // if user selects C
    else if ((strCh == "C") || (strCh == "c"))
    {

        //user has wants to add a new post
        cout << "Adding a new post..." << endl;
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
        cout << "Bye..." << endl;
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
        cout << strCh << " is not a valid option." << endl;
    }
}


void DisplayBlogAreas(vector<Area> areas)
{
    cout << "Display Blog areas..." << endl;
    //user has selected to display blog areas
    for (int i = 0; i < areas.size(); i++)
    {
        cout << "Area Index:" << i << endl;
        cout << areas[i] << endl;
        cout << "******************" << endl;
    }
}

void DisplayPostsABlog(Area a)
{
    cout << "Posts for " << a.getName() << endl;

    //user has selected to display blog areas
    for (int i = 0; i <= a.getIndxLastPost(); i++)
    {
        Post p;
        bool found = a.getPost(i, p);
        if (found)
        {
            cout << "Post Index:" << i << endl;
            cout << p << endl;
            cout << "******************" << endl;
        }
    }

}

void DisplayOneBlogPost(vector<Area> areas)
{
    int areaIndex, blogIndex;
    areaIndex = getValidBlogArea();

    cout << "Please enter a valid post id for: " << areas[areaIndex].getName() << "\n";
    cin >> blogIndex;

    Post p;
    bool found = areas[areaIndex].getPost(blogIndex, p);
    while(!found)
    {
        cout << "Please enter a valid post id for: " << areas[areaIndex].getName() << "\n";
        cin >> blogIndex;
        found = areas[areaIndex].getPost(blogIndex, p);
    }

    cout << "Post Index:" << blogIndex << endl;
    cout << p << endl;
    cout << "******************" << endl;

}

int getValidBlogArea()
{
    int area;
    //prompt and read in Blog Area Index
    cout << "Please enter in a Blog Area Index" << endl;
    cin >> area;
    //input validation loop
    while ((area < 0) || (area >= 5))
    {
        cout << "Please enter in a Blog Area Index" << endl;
        cin >> area;
    }
    //return valid Blog Area Index
    return area;
}

Post userAddPost(vector<Area> &areas, int areaIndex)
{

    Post p;

    string Title;
    cin.ignore();
    do
    {
        cout << "Please enter in the title..." << endl;
        Title = getValidString(20);
        p.setTitle(Title);
    }while(!compareTitles(p, areas[areaIndex]));

    cout << "Please enter in the text..." << endl;
    string Text = getValidString(500);

    p.setTitle(Title);
    p.setText(Text);
    p.setUser(areas[areaIndex].getUsername());

    cout << "Post added successfully.\n";

    return p;
}

void editPost(vector<Area> &areas)
{
    int areaIndex, blogIndex;
    areaIndex = getValidBlogArea();

    if(areas[areaIndex].checkEmpty())
        cout << "This blog has no posts to edit." << endl;
    else
    {
        cout << "Please enter a valid post id for: " << areas[areaIndex].getName() << "\n";
        cin >> blogIndex;

        Post p;
        bool found = areas[areaIndex].getPost(blogIndex, p);

        while (!found)
        {
            cout << "Please enter a valid post id for: " << areas[areaIndex].getName() << "\n";
            cin >> blogIndex;
            found = areas[areaIndex].getPost(blogIndex, p);
        }

        cout << p << endl;

        string Title;
        cin.ignore();
        do
        {
            cout << "Please enter in the title..." << endl;
            Title = getValidString(20);
            p.setTitle(Title);
        } while (!compareTitles(p, areas[areaIndex]));
        cout << "Please enter in the text..." << endl;
        string Text = getValidString(500);

        p.setTitle(Title);
        p.setText(Text);
        p.setUser(areas[areaIndex].getUsername());
        areas[areaIndex].copyPost(blogIndex, p);
        cout << "Post Edited" << endl;
    }

}

void deletePost(vector<Area> &areas)
{
    int areaIndex, blogIndex;
    areaIndex = getValidBlogArea();


    if(areas[areaIndex].checkEmpty())
        cout << "This blog has no posts." << endl;
    else
    {
        cout << "Please enter a valid post id for: " << areas[areaIndex].getName() << "\n";
        cin >> blogIndex;
        Post p;

        bool found = areas[areaIndex].getPost(blogIndex, p);
        while(!found)
        {
            cout << "Please enter a valid post id for: " << areas[areaIndex].getName() << "\n";
            cin >> blogIndex;
            found = areas[areaIndex].getPost(blogIndex, p);
        }
        areas[areaIndex].DeletePost(blogIndex);
        cout << "Post Index:" << blogIndex << " deleted."<< endl;

    }

}

const string WHITESPACE = " \n\r\t\f\v";

string ltrim(const string &s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}

string rtrim(const string &s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

string trim(const string &s)
{
    return rtrim(ltrim(s));
}

string getValidString(int maxChars)
{
    string text;
    do {
        cout << "Please enter in a string with at least 1 character and at most " << maxChars << " characters." << endl;
        getline(cin, text);
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
            cout << "Another post in this blog has this identical title" << endl;
            cout << "Please enter a new unique title" << endl;
            return false;
        }
    }
    return true;
}

void saveData(vector <Area> areas)
{
    ofstream outputFile("Areas.txt");
    ofstream outputFile2("Posts.txt");
    if(outputFile.fail())
    {
        cout<<"Error opening Areas.txt";
        exit(1);
    }
    outputFile << areas.size() << endl;

    for (int i=0;i < areas.size();i++)
    {
        outputFile<< areas[i].getName()<<endl;
        outputFile<< areas[i].getDescription()<<endl;
        outputFile << areas[i].getIndxLastPost() << endl;

        for (int j=0; j <= areas[i].getIndxLastPost();j++)
        {
            Post p;
            bool found = areas[i].getPost(j, p);
            if (found)
            {
                outputFile2 << p.getTitle() << endl;
                outputFile2 << p.getUser() << endl;
                outputFile2 << p.getText() << endl;
                outputFile2 << p.getLove() << endl;
                outputFile2 << p.getLike() << endl;
                outputFile2 << p.getDislike() << endl;
                outputFile2 << p.getHate() << endl;
            }
        }

    }
    outputFile.close();
    outputFile2.close();
}

void readData(vector <Area> &areas)
{
    ifstream areasFile("Areas.txt");
    ifstream postFile("Posts.txt");
    Post p;
    string blogTitle,descrip, title, user, text;
    int areaIndex=0, blogSize=0;

    if(areasFile.fail())
    {
        cout << "Error: Could not open Area file.";
        exit(1);
    }

    if(postFile.fail())
    {
        cout << "Error: Could not open Post file.";
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
int login(const vector<T*> users, vector <Area> &areas)
{
    string name, alias, pwd, enteredAlias, enteredPwd;
    bool comparison = false;
    int i;

    while(!comparison)
    {
        cout << "Enter your username/alias: ";
        getline(cin , enteredAlias);
        for(i = 0; i < users.size(); i++)
        {
            name = users[i]->getAlias();
            if(enteredAlias == name)
            {
                pwd = users[i]->getPassword();
                cout << "Enter your password: ";
                getline(cin, enteredPwd);
                while(enteredPwd != pwd)
                {
                    cout << "Enter your password: ";
                    getline(cin, enteredPwd);
                }

                cout << *users[i] << endl;
                for(auto & area : areas)
                    area.setUser(*users[i]);

                comparison = true;
                return i;
            }
        }
    }

    return 0;
}

void reactToPost(vector<Area> &areas)
{
    int areaIndex, blogIndex;
    areaIndex = getValidBlogArea();
    char choice;

    cout << "Please enter a valid post id for: " << areas[areaIndex].getName() << "\n";
    cin >> blogIndex;

    Post p;
    bool found = areas[areaIndex].getPost(blogIndex, p);
    while(!found)
    {
        cout << "Please enter a valid post id for: " << areas[areaIndex].getName() << "\n";
        cin >> blogIndex;
        found = areas[areaIndex].getPost(blogIndex, p);
    }

    cout << "Enter:\n";
    cout << "A to love the post." << endl;
    cout << "B to like the post." << endl;
    cout << "C to dislike the post." << endl;
    cout << "D to hate the post." << endl;

    cin >> choice;
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
        cout << "Invalid option" << endl;
}

void deleteArea(vector<Area> &areas)
{
    //checks user type to make sure that the user has permission to perform this action
    if(areas[0].getUType() != 1)
        cout << "You do not have permission to perform this action. Only Superusers can delete areas." << endl;
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

        cout << "Blog Index: " << areaIndex << " deleted" << endl;

    }
}

template <class T>
void changeAlias(T *u, vector<Area> &areas)
{
    u->changeAlias();
    //updates user info for all areas
    for(auto & area : areas)
        area.setUser(*u);
}

template <class T>
void ListTransfer(const vector<T*> user, UserList<User> *uList)
{
    for (int i = 0; i < user.size(); i++)
    {
        uList->addToList(user[i]);
        //cout << "Added user: " << user[i] << " to the list.\n";
    }
}
