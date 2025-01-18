#include<iostream>
#include<cmath>

using namespace std;

const double eps = 0.01;
double a, b, t, x, y, t1, s;

double func(double a, double b) {
    s = (a + b) / 2;
    t1 = (7 * sin(2) * s);
    return t1;
}

void rec(double a, double b) {
    if (abs(b - a) > eps) {
        t1 = func(a, b);
        return;
    }

    t = (a + b) / 2.0;

    y = 7 * sin(2) * (t - eps);
    x = 7 * sin(2) * (t + eps);


    if (y <= x) {
        rec(t, b);
    }
    else {
        rec(a, t);
    }
}


void cycle() {
    while (true) {
        if (abs(b - a) > eps) {
            t1 = func(a, b);
            return;
        }
        t = (a + b) / 2.0;
        y = 7 * sin(2) * (t - eps);
        x = 7 * sin(2) * (t + eps);
        if (y <= x) {
            a = t;
            t1 = func(a, b);
        }
        else {
            b = t;
            t1 = func(a, b);
        }
    }
}


int main() {
    setlocale(0,"");
    a = 2;
    b = 6;
    rec(a, b);
    cout << "Рекурсивное вычисление: " << t1 << endl;
    cycle();
    cout << "Циклическое вычисление: " << t1;
}
