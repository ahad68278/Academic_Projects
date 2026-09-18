#include<iostream>
using namespace std;

class DAC
{
    public:
    string owner;
    string* layerdata;

    DAC(string a, string b)
    {
        owner = a;     
        layerdata = new string (b) ;
        cout<<owner<<endl<<*layerdata<<endl;
    }
    ~DAC(){
        delete layerdata;
        cout<<"Destructor: Memory freed for "<<owner<<endl;
    }
};

int main()
{
    DAC( "Sam" , "Original Painting" ); 
    cout<<"NIGGA";    
    system("pause");
}


