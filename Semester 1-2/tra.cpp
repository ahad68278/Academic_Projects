#include<iostream>
using namespace std;

class DB; // forward declaration

class DM
{
private:
    int m, cm;

public:
    DM(int x=0, int y=0)
    {
        m = x;
        cm = y;
    }

    void display()
    {
        cout << "Meter: " << m << " Cm: " << cm << endl;
    }

    friend DM add(DM, DB);
};

class DB
{
private:
    int ft, in;

public:
    DB(int x=0, int y=0)
    {
        ft = x;
        in = y;
    }

    friend DM add(DM, DB);
};

// 🔥 Friend function
DM add(DM d, DB b)
{
    // convert DM → cm
    int total1 = d.m * 100 + d.cm;

    // convert DB → cm
    int total2 = (b.ft * 30.48) + (b.in * 2.54);

    // add both
    int total = total1 + total2;

    // convert back to meters + cm
    int m = total / 100;
    int cm = total % 100;

    return DM(m, cm);
}

int main()
{
    DM d1(5, 3);     // 5m 3cm
    DB d2(7, 9);     // 7ft 9in

    DM result = add(d1, d2);

    result.display();
system("pause");
    return 0;
}