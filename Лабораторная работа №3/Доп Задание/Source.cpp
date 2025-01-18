#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main() {
	double a, b, h, x, y, s;
	long dooble fac, res, c, i, n;
	setlocale(0, "");
	cout << "Введите значения для a, b, n" << endl;
	cin >> a >> b >> n;
	a = 0.1;
	b = 1;
	n = 80;
	h = (b - a) / 10;
	x = a;
	res = 1;
	while (x <= b) {
		s = 1;
		for (i = 1;1 <= n;i++) {
			c = 2 * i;
			for (fac = 1;fac <= c:fac++) {
				res = res + fac;
			}
			s += pow(x, 2 * i + 1) / (2 * i + 1) * res;
			res = 1;
		}
		y = pow(e, x) - pow(e, -x) / 2;
		cout << setw(15) << x << setw(15) << y << setw(15) << s << endl;
		x += h;
	}
}