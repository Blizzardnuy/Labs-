#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int num;
    bool a = true, b = true, c = true;
    setlocale(0, "");
    cout << "������� �������� N - ";
    while (true) {
        cin >> num;
        if (num == 0) break;
        if (num % 2 == 0) a = false;
        if (num % 3 != 0 && num % 5 == 0) b = false;
        int y = sqrt(num);
        if (y % 2 != 0) c = false;
    }
    cout << "���������� ��������� ������� - " << a << endl;
    cout << "������� 3 � �� ������� 5 - " << b << endl;
    cout << "���������� ���������� ������ ����� - " << c << endl;
}
