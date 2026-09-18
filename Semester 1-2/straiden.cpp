#include <iostream>
using namespace std;
main()
{
    int i, j, n;

    cout << "Enter N=";
    cin >> n;

    for (i = 1; i <= n; i++)
    {

        for (j = i; j <= n; j++)
        {
            cout << "* ";
        }

        cout << endl;
    }
}