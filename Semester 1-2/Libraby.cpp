#include<iostream>
using namespace std;

class Book{
    protected:
    string title,auther;
    int copies;
    public:
    Book (string t, string a, int c):title(t),auther(a),copies(c){}

    void setTitle(string  t) { title=t;  }
    void setAuther(string a) { auther=a; }
    void setCopies(int    c) { copies=c; }

    string getTitle () { return title;  }
    string getAuther() { return auther; }
    int    getCopies() { return copies; }

    void showBook(){
        cout<<"Books ";
    }
};