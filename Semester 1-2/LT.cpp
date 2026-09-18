#include<iostream>
using namespace std;
class Person{
    public:
    string name;
    int yearOfBirth;
    Person(string n=" ", int y=0):name(n),yearOfBirth(y){}
};
class Student:public Person{
    public:
    int studentID;
    Student(string n=" ", int y=0,int id=0):Person(n,y){
        studentID=id;
    }
};
class Employee:public Person{
    public:
    int empID;
    Employee(string n=" ", int y=0,int id=0):Person(n,y){
        empID=id;
    }
};
class ResearchAssistant:public Student, public Employee{
    public:
    string researchArea;
    ResearchAssistant(string n,int y,int sid,int eid,string r)
    :Student(n,y,sid),Employee(n,y,eid){
        researchArea=r;
    }
};
class Book{
    public:
    string title;
    string author;
    int copies;
    Book(string t=" ",string a=" ",int c=0){
        title=t;
        author=a;
        copies=c;
    }
    friend void borrowBook(Student &s, Book &b);
};
void borrowBook(Student &s, Book &b){
    cout<<"Student: "<<s.name<<endl;
    cout<<"Book: "<<b.title<<" by "<<b.author<<endl;
    if(b.copies>0){
        b.copies--;
        cout<<"Borrowed Successfully"<<endl;
        cout<<"Remaining Copies: "<<b.copies<<endl;
    }else{
        cout<<"No Copies Available"<<endl;
    }
}
int main(){
    Student s1("Ali",2003,101);
    Book b1("OOP","Ahad",2);

    borrowBook(s1,b1);
    borrowBook(s1,b1);
    borrowBook(s1,b1);
    system("pause");
    return 0;
}