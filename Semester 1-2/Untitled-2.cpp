#include <iostream>
using namespace std;
main()
{
    int i, j, n = 7;

    for (i = 1; i <= 4; i++)
    {

        for (int k = 3 - i; k >= 0; k--)
        {
            cout << " ";
        }

        for (j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (i = 3; i >= 1; i--)
    {
        for (int k = i - 1; k <= 2; k++)
        {
            cout << " ";
        }

        for (j = i; j >= 1; j--)
        {
            cout << "*";
        }
        cout << endl;
    }
}
