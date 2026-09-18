#include<iostream>
using namespace std;

class DB;
class DM
{
    private:
    int m;
    int cm; 
    public:
    DM (int x, int y)
    {
        m=x;
        cm=y;
    }
    friend DM dm(DM , DB);
};
class DB
{
    private:
    int i;
    int f;
    public:
    DB (int z, int zz)
    {
        i=z;
        f=zz;
    }
    friend DM dm(DM ,DB);
};

DM dm(DM d, DB b)
{
    int Total;
    int total;
    Total = d.m + b.f;
    total = d.cm + b.i;
    cout<<Total<<endl<<total;
}

int main()
{
    DM d1(5,3);
    DB d2(7,9);
    dm(d1 , d2);
    system("pause");
}