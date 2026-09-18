#include<iostream>
using namespace std;
void In(int a[b][c])
{
    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << "Enter the Marks of student " << j << " : ";
            cin >> a[i][j];
        }
    }
}
int main()
{
    int b,c;
    int a[b][c];
    cout << "Enter the No. of students : ";
    cin >> b;
    int *p1=&b;
    cout << "Enter the No. of subjects : ";
    cin >> c;
    In(a);
}