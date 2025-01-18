#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main() {
	double a, b, h, x, y, s;
	long double fac, g, c, i, n;
	a = 0.1;
	b = 1;
	n = 80;
	h = (b - a) / 10;
	x = a;
	g = 1;
	while (x <= b) {
		s = 0;
		for (i = 0;i <= n;i++) {
			c = 2 * i + 1;
			for (fac = 1;fac <= c;fac++) {
			g = g * fac;
			}
			s += pow(x,c) / g;
			g = 1;
		}
		y = (pow(2.7182818284590452353602874713527, x) - pow(2.7182818284590452353602874713527, -x)) / 2;
		cout << setw(15) << x << setw(15) << y << setw(15) << s << endl;
		x += h;
	}
}
