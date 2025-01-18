#include <iostream>
//Задание номер 3: Даны два нулевых числа.Найти сумму,разность,произведение и частное их квадратовъ
//cout видишь?) водишь значения и не паришься
using namespace std;

int main() {
	setlocale(0, "");
	double a, b;
	cout << "А = ";
	cin >> a;
	cout << "Б = ";
	cin >> b;
	a *= a;
	b *= b;
	cout << a + b << endl << a - b << endl << a * b << endl << a / b << endl;
}