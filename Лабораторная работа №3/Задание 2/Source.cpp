#include <iostream>
using namespace std;
int main() {
    int a, b = 1;
    setlocale(0, "");
    while (a > 0) {
        cin >> a;
        b *= a;
    }
    cout << "Значение - " << b << endl;
}
