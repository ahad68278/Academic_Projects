#include <iostream>
using namespace std;

// Function template to find the maximum of 4 values
template <typename T>
T findMax(T a, T b, T c, T d) {
    T maxVal = a; // assume first value is maximum
    if (b > maxVal) maxVal = b;
    if (c > maxVal) maxVal = c;
    if (d > maxVal) maxVal = d;
    return maxVal;
}

int main() {
    int i1, i2, i3, i4;
    float f1, f2, f3, f4;

    // Input 4 integers
    cout << "Enter 4 integers:\n";
    cin >> i1 >> i2 >> i3 >> i4;

    // Input 4 floats
    cout << "Enter 4 floats:\n";
    cin >> f1 >> f2 >> f3 >> f4;

    // Use template function to find maximum
    int maxInt = findMax(i1, i2, i3, i4);
    float maxFloat = findMax(f1, f2, f3, f4);

    // Display results
    cout << "Maximum integer: " << maxInt << endl;
    cout << "Maximum float: " << maxFloat << endl;

    return 0;
}
