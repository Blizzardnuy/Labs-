#include <iostream>
using namespace std;

int main() {
    int lenght, c, d;
    setlocale(0, "");
    cout << "Введите размер массива: ";
    cin >> lenght;
    int* a = new int[lenght];
    cout << "Введите c и d" << endl;
    cin >> c;
    cin >> d;
    for (int i = 0; i < lenght;i++) {
        cin >> *(a + i);
    }
    for (int i = 0; i < lenght;i++) 
        if (c <= *(a + i) && *(a + i) <= d) {
            cout << *(a + i) << " ";
        }
    }
    delete[] a;
    //0 1 2 3 4 5 6 7 8 9 10
}

