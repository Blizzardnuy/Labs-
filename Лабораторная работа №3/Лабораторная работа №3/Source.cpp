#include<iostream>

using namespace std;
int main() {
        int a, b, c = 0;
        setlocale(0, "");
        cout << "������� �: ";
        cin >> a;
        cout << "������� �������� B: ";
        cin >> b;
        for (;a<=b;a++) {
            c += pow(a,2);
            cout << c << "_" ;
        }
    }