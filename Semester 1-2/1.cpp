#include <iostream>
using namespace std;
class SmartLight
{
    public:
    int bri = 0;
    string color = "white" ;
    SmartLight ()
    {
        cout<<"Smart Light"<<endl;
        cout<<"Brightness = "<<bri<<endl;
        cout<<"Color = "<<color<<endl;
        cout<<" "<<endl;
    }
    SmartLight (int bri, string color)
    {
        cout<<"Smart Light"<<endl;
        cout<<"Brightness = "<<bri<<endl;
        cout<<"Color = "<<color;
    }
};
int main()
{
    SmartLight SL;
    SmartLight sl(5, "Blue");
    
    return 0;
}