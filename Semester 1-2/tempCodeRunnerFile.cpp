#include<iostream>
using namespace std;
int main()
{
    int sum=0,t=2;
    cout<<"Series "<<endl;
    
    cout<<t<<"+";

    for(int i=1; i<5; i++)
    {
        t=(t*10)+2;
        if(i<4)
        {
        cout<<t<<"+";
        }
        else
        {
            cout<<t;
        }
    }
    
}