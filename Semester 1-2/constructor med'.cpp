#include<iostream>
using namespace std;

class Post
{
    public:
    string user;
    string text;
    int likeC;

    Post(string u,string t,int C)
    {
        user = u;
        text = t;
        likeC = C;
        cout<<user<<endl<<"'"<<text<<"' "<<endl<<likeC<<endl;
    }
    Post(string u,string t):Post(u,t,0)
    {
    }
};
int main()
{
    Post("Sam","I like being Pegged",2300);
    Post("Morfy","I hate being Pegged");
    int a;
    cin>>a;
}