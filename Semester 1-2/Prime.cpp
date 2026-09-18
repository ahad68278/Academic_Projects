#include <iostream>
using namespace std;
int isPrime(int);
int isOdd(int);
int main()
{
    int num = 50, second, first;

    for (first = 2; first < num; first++)
    {
        second = 20 - first;
        if (isPrime(first) && isPrime(second))
        {
            cout << second << " + " << first << " = 20" << endl;
        }
    }

    return 0;
}

int isPrime(int num)
{
    if (num <= 1)
        return 0;
    for (int i = 2; i < num / 2; i++)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}
