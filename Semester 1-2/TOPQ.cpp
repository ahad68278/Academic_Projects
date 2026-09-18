#include<iostream>
using namespace std;

class Person{
    protected:
    string name;
    private: 
    int age;
    static int count;
    
    public:
    Person (string n = "", int a=0):name(n),age(a){

    }
    
    static void showPerson()
    {
        cout << count << endl;
    }

};
int Person::count=0;
class Student:public Person
{
    private:
    int rollno;
    public:
    Student(int rollno):Person(name,)
    void showStudent()
    {

    }
};
class Employee:protected Person{
    private: 
    int salary;
    public:
    void showEmployee()
    {

    }
};
class Intern:private Student{
    private: 
    int duration;
    public:
    void showIntern()
    {

    }
};
class Manager:public Employee , public Student{

};

int main()
{
    Student S;
    Employee E;
    Intern I;
    Manager M;

}