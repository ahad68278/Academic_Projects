#include <iostream>
using namespace std;

int main() {
    int n = 5;  // example value for n
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= 5; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}
