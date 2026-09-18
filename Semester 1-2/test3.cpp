#include <iostream>
using namespace std;

struct Employee {
    int Emp_Id;
    char Emp_Name[50];  // Using char array instead of string
    double Emp_Salary;
};

void addRecord(Employee emp[], int &n) {
    cout << "How many employees? ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter ID: "; cin >> emp[i].Emp_Id;
        cout << "Enter Name: "; cin >> emp[i].Emp_Name;  // Single word
        cout << "Enter Salary: "; cin >> emp[i].Emp_Salary;
    }
}

void sortRecord(Employee emp[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (emp[j].Emp_Salary > emp[j+1].Emp_Salary)
            {
                Employee temp = emp[j];
                emp[j] = emp[j+1];
                emp[j+1] = temp;
            }
}

void displayRecords(Employee emp[], int n) {
    cout << "ID\tName\tSalary"<<endl;
    for (int i = 0; i < n; i++)
        cout << emp[i].Emp_Id << "\t" << emp[i].Emp_Name << "\t" << emp[i].Emp_Salary << endl;
}

int main() {
    Employee employees[100];
    int n;
    addRecord(employees, n);
    sortRecord(employees, n);
    displayRecords(employees, n);
    return 0;
}
