#include <iostream>
using namespace std;
void Max(int a, int b, int c);
main()
{
    int a, b, c;
    cout<<"Enter Numbers ";
    cin >> a >> b >> c;
    Max(a, b, c);
}

void Max(int a, int b, int c)
{
    if (a > b && a > c)
    {
        cout << "a is the greatest";
    }
    else if(b>a&&b>c)
    {
        cout << "b is the greatest";
    }
    else
    {
        cout<<"c is the greatest";
    }
}