#include <iostream>
using namespace std;
main()
{
    int a[4], b, c, d;
    cout << "Enter numbers=";

    for (b = 0; b <= 4; b++)
    {
        cin >> a[b];
    }
    for (b = 0; b <= 4; b++)
    {
        cout << a[b] << ",";
    }

    c = a[1];
    d = a[1];

    for (b = 1; b <= 5; b++)
    {
        if (a[b] > c)
        {
            c = a[b];
        }
        if (a[b] < d)
        {
            d = a[b];
        }
    }
    cout << endl
         << "Max=" << c << endl;
    cout << "Min=" << d << endl;
}