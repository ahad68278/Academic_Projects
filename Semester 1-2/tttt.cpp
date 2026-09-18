#include <iostream>
using namespace std;
class water {
private:
    int f;
protected:
    int H, O, M;
public:
    int mitha;
    water() : H(2), O(1), mitha(5) {
        cout << "Mitha is = " << mitha << endl;
    }

    water(int a) {
        M = a;
    }

    int d;
};
class sharbat : public water {
public:
    void set() {
        cout << "Enter the value of d = ";
        cin >> d;
    }
};
int main() {
    sharbat a1;           
    a1.mitha = 6;        
    cout << "Mitha is now = " << a1.mitha << endl;
    system("pause");
    return 0;
}
