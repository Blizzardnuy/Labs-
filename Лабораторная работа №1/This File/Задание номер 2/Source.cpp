#include <iostream>
//������� ����� 2: ��������� �������� ���������� ��������� ��� �������� ��������� ���������� ����������
//��� �� ���� ���� ������ �� �������� ������ �������
using namespace std;

int main() {
	setlocale(0, "");
	bool x = 0, y = 0, z = 1;
	cout << (x || y && !z) << endl;
	cout << (!x && !y) << endl;
	cout << (!(x && z) || y) << endl;
}