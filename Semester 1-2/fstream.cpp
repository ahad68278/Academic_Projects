#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct clod
{
    int Srno[4] = {1, 2, 3, 4};
    int Reg[4] = {1225, 1226, 1227, 1228};
    string Pr[4] = {"30,000", "40,000", "50,000", "45,000"};
    string name[4] = {"Ramzan", "Noor", "Aslam", "Wahid"};
};

// ======================== DELETE FUNCTION ==========================
void dele(int pk)
{
    string line;
    bool found = false;
    ifstream ifs("ABC.txt");
    ofstream ofs("temp.txt");

    getline(ifs, line);  // copy header
    ofs << line << endl;

    while (getline(ifs, line))
    {
        int sno, reg;
        string name, p;

        // --- Fixed parsing using stringstream and getline with tabs
        stringstream ss(line);
        ss >> sno >> reg;
        ss.ignore();              // skip tab
        getline(ss, name, '\t');  // read name
        getline(ss, p);           // read salary

        if (reg == pk)
        {
            found = true;
            continue;  // skip this line (delete)
        }

        // write the line to temp file
        ofs << sno << "\t" << reg << "\t" << name << "\t" << p << endl;
    }

    ifs.close();
    ofs.close();

    if (found)
    {
        remove("ABC.txt");
        rename("temp.txt", "ABC.txt");
        cout << "Record deleted successfully." << endl;
    }
    else
    {
        remove("temp.txt");
        cout << "Record not found." << endl;
    }
}

// ======================== EDIT FUNCTION ==========================
void edit(int pk)
{
    string line;
    bool found = false;
    ifstream ifs("ABC.txt");
    ofstream ofs("temp.txt");

    getline(ifs, line);  // copy header
    ofs << line << endl;

    while (getline(ifs, line))
    {
        int sno, reg;
        string name, p;

        // --- Fixed parsing
        stringstream ss(line);
        ss >> sno >> reg;
        ss.ignore();              // skip tab
        getline(ss, name, '\t');  // read name
        getline(ss, p);           // read salary

        if (reg == pk)
        {
            found = true;

            // --- Fixed input: cin.ignore() before getline to avoid skipping
            cout << "Enter new regno : ";
            cin >> reg;
            cin.ignore();  // important!

            cout << "Enter new name : ";
            getline(cin, name);

            cout << "Enter new Salary : ";
            getline(cin, p);
        }

        ofs << sno << "\t" << reg << "\t" << name << "\t" << p << endl;
    }

    ifs.close();
    ofs.close();

    if (found)
    {
        remove("ABC.txt");
        rename("temp.txt", "ABC.txt");
        cout << "Record edited successfully." << endl;
    }
    else
    {
        remove("temp.txt");
        cout << "Record not found." << endl;
    }
}

// ======================== MAIN FUNCTION ==========================
int main()
{
    clod veh;
    string line;

    // Display initial data
    cout << "Sr.no\tEmp No.\tName\tSalary" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << veh.Srno[i] << "\t"
             << veh.Reg[i] << "\t"
             << veh.name[i] << "\t"
             << veh.Pr[i] << endl;
    }

    // Write initial data to file
    ofstream ofs("ABC.txt");
    ofs << "Sr.no\tEmp No.\tName\tSalary" << endl;
    for (int i = 0; i < 4; i++)
    {
        ofs << veh.Srno[i] << "\t"
            << veh.Reg[i] << "\t"
            << veh.name[i] << "\t"
            << veh.Pr[i] << endl;
    }
    ofs.close();

    cout << "\nAfter opening file:" << endl;
    ifstream ifs("ABC.txt");
    while (getline(ifs, line))
    {
        cout << line << endl;
    }
    ifs.close();

    // DELETE
    int pk;
    cout << "\nEnter the Emp No. you want to delete : ";
    cin >> pk;
    dele(pk);

    // Display after delete
    cout << "\nAfter Update:" << endl;
    ifs.open("ABC.txt");
    while (getline(ifs, line))
    {
        cout << line << endl;
    }
    ifs.close();

    // EDIT
    cout << "\nEnter the Emp No. you want to edit : ";
    cin >> pk;
    edit(pk);

    // Display after edit
    cout << "\nAfter Edit:" << endl;
    ifs.open("ABC.txt");
    while (getline(ifs, line))
    {
        cout << line << endl;
    }
    ifs.close();

    return 0;
}
