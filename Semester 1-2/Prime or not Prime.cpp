#include <iostream>
using namespace std;
int isPrime(int);
int isOdd(int);
int main()
{
    int num = 50, second, first;
    cout<<"  Output 1 "<<endl<<endl;
    for (first = 2; first < num; first++)
    {
        second = 100 - first;
        if (isPrime(first) && isPrime(second))
        {
            cout << second << " + " << first << " = 100" << endl;
        }
    }
    cout <<endl<< "**************" << endl<<endl;
    cout<<"  Output 2 "<<endl<<endl;

    for (first = 1; first <= 15; first++)
    {
        second = 30 - first;
        if (isOdd(first) && isOdd(second))
        {
            cout << second << " + " << first << " = 100 " << endl;
        }
    }
    return 0;
}

int isPrime(int num)
{
    if(num<=1)
    return 0;
    for (int i = 2; i < num/2; i++)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int isOdd(int num)
{
    return (num % 2 != 0);
}

