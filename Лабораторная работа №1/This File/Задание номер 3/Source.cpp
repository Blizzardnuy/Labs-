#include <iostream>
//������� ����� 3: ���� ��� ������� �����.����� �����,��������,������������ � ������� �� ����������
//cout ������?) ������ �������� � �� ��������
using namespace std;

int main() {
	setlocale(0, "");
	double a, b;
	cout << "� = ";
	cin >> a;
	cout << "� = ";
	cin >> b;
	a *= a;
	b *= b;
	cout << a + b << endl << a - b << endl << a * b << endl << a / b << endl;
}