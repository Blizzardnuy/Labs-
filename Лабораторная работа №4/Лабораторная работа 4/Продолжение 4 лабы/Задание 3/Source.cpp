#include <iostream>
using namespace std;

int main() {
    setlocale(0, "");
    const int a = 5, b = 10;
    long long max = 0;
    double matrix[a][b];
    for (int i = 0;i < a;i++) {
        for (int j = 0;j < b;j++) {
            int input;
            cin >> input;
            if (abs(input) > max) max = abs(input);
            matrix[i][j] = input;
        }
    }
    cout << endl;

    for (int i = 0;i < a;i++) {
        for (int j = 0;j < b;j++) {
            cout << matrix[i][j] / max << "  ";
        }
        cout << endl;
    }


}