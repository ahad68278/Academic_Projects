#include <iostream>
#include <string>

using namespace std;

// Forward declarations so Employee knows these classes exist
class Administration;
class DeanHOD;

// ==========================================
// 1. Class Person
// ==========================================
class Person {
protected:
    string name;
    int year_of_birth;

public:
    Person(string n, int yob) : name(n), year_of_birth(yob) {}
};

// ==========================================
// 2. Class Employee (Inherits from Person)
// ==========================================
class Employee : public Person {
protected:
    string employeeID;
    int joiningYear;
    string jobTitle;
    string courseID;
    string courseTitle;

public:
    Employee(string n, int yob, string eID, int jYear, string jTitle, string cID, string cTitle)
        : Person(n, yob), employeeID(eID), joiningYear(jYear), jobTitle(jTitle), 
          courseID(cID), courseTitle(cTitle) {}

    // Grant permission to specific classes to modify protected attributes
    friend class Administration;
    friend class DeanHOD;
    friend class Academic;
};

// ==========================================
// 3. Class Student (Inherits from Person)
// ==========================================
class Student : public Person {
private:
    string studentID;
    string enrolledSemester;

public:
    // Four-argument constructor
    Student(string n, int yob, string sID, string sem) 
        : Person(n, yob), studentID(sID), enrolledSemester(sem) {}

    void display() {
        cout << "--- Student Information ---" << endl;
        cout << "Name: " << name << endl;
        cout << "Year of Birth: " << year_of_birth << endl;
        cout << "Student ID: " << studentID << endl;
        cout << "Semester: " << enrolledSemester << endl << endl;
    }
};

// ==========================================
// 4. Class Administration (Inherits from Employee)
// ==========================================
class Administration : public Employee {
public:
    // Constructor: Sets course attributes to "NULL" as per requirements
    Administration(string n, int yob, string eID, int jYear, string jTitle)
        : Employee(n, yob, eID, jYear, jTitle, "NULL", "NULL") {}

    // Methods to set/get job title of another employee
    void setJobTitle(Employee &e, string title) {
        e.jobTitle = title;
    }

    string getJobTitle(Employee &e) {
        return e.jobTitle;
    }
};

// ==========================================
// 5. Class Academic (Inherits from Employee)
// ==========================================
class Academic : public Employee {
public:
    // Constructor: Sets employee details to "NULL"/0 as per requirements
    Academic(string n, int yob, string cID, string cTitle)
        : Employee(n, yob, "NULL", 0, "NULL", cID, cTitle) {}

    void setCourseID(string id) { courseID = id; }
    void setCourseTitle(string title) { courseTitle = title; }

    void displayAcademic() {
        cout << "--- Academic Member Details ---" << endl;
        cout << "Name: " << name << endl;
        cout << "Employee ID: " << employeeID << endl;
        cout << "Job Title: " << jobTitle << endl;
        cout << "Course: " << courseTitle << " [" << courseID << "]" << endl << endl;
    }
};

// ==========================================
// 6. Class DeanHOD (Inherits from Administration)
// ==========================================
class DeanHOD : public Administration {
public:
    DeanHOD(string n, int yob, string eID, int jYear, string jTitle)
        : Administration(n, yob, eID, jYear, jTitle) {}

    // Special privilege: Modify ID, Designation, Course ID, and Course Name
    void modifyEmployeeRecords(Employee &e, string newID, string newTitle, string newCID, string newCTitle) {
        e.employeeID = newID;
        e.jobTitle = newTitle;
        e.courseID = newCID;
        e.courseTitle = newCTitle;
        cout << "** [System] DeanHOD has updated records for " << e.name << " **" << endl << endl;
    }
};

// ==========================================
// Main Function: Demonstration
// ==========================================
int main() {
    // 1. Create Student
    Student s1("Alice Smith", 2005, "FA23-BSCS-05", "4th");
    s1.display();

    // 2. Create Academic (Initial state has NULL employee data)
    Academic prof("Dr. Robert", 1980, "CS101", "Programming Fundamentals");
    cout << "Initial Academic State (Before Dean Intervention):" << endl;
    prof.displayAcademic();

    // 3. Create Administration and DeanHOD
    Administration adminOfficer("James Bond", 1988, "ADM-007", 2018, "Registrar");
    DeanHOD dean("Dr. Sarah", 1972, "DEAN-01", 2008, "Dean of Sciences");

    // 4. Test DeanHOD privileges (Updating the Academic member's NULL fields)
    dean.modifyEmployeeRecords(prof, "EMP-999", "Senior Lecturer", "CS502", "Advanced C++");

    // 5. Test Administration set/get
    adminOfficer.setJobTitle(prof, "Principal Researcher");
    
    cout << "Final Academic State:" << endl;
    prof.displayAcademic();

    cout << "Admin verification - New Job Title: " << adminOfficer.getJobTitle(prof) << endl;
system("pause");
    return 0;
}