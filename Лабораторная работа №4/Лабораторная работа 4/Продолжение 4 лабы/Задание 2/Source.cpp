#include <iostream>
using namespace std;

int main() {
    setlocale(0, "");
    int c, r;
    cout << "������� ���������� ��������: ";
    cin >> c;
    cout << "������� ���������� �����: ";
    cin >> r;
    char** matrix = new char* [r];
    for (int i = 0; i < r; ++i) {
        matrix[i] = new char[c] {0};
    }
    for (int i = 0;i < c;i++) {
        for (int k = 0;k < r;k++) {
            cin >> matrix[i][k];
        }
    }
    for (int i = 0;i < c;i++) {
        for (int k = 0;k < r;k++) {
            if (matrix[i][k] == 'w') {
                if (k - 1 == -1) {
                    cout << "w ������ � ������" << endl;
                    break;
                }
                cout << k << " ��������� ����� �� w" << endl;
            }
        }
    }
}
