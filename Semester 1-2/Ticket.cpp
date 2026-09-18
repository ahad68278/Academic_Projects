#include<iostream>
using namespace std;

class Ticket
{
    public:

    string name;
    string vipID;
    int seat;
    Ticket(string n, int s, string i)
    {
        name = n;
        vipID = i;
        seat = s;
        if(s<0)
        {
            s=0;
        }
        cout<<" --- Ticket Issued --- "<<endl;
        cout<<"Name: "<<n<<endl<<"Seat: "<<s<<endl<<"Status: "<<i<<endl<<endl;
    }
   
    Ticket(string n,int s):Ticket(n,s,"NONE")
    {

    }
};
int main()
{
    Ticket("San", 34 ,"VIP-026");
    
    Ticket("Jane",-12);

    Ticket("Morfy",12);

    system("pause");
}