#include <iostream>
using namespace std;

int main()
{
    int rows = 5;

    for (int i = 1; i <= rows; i++)
    {
        int num = 1;
        cout << num ;
        for (int j = 2; j < i; j++)
        {

            cout<<" "<<4*(j-1) ;
        }
        cout << endl;
    }

    return 0;
}
