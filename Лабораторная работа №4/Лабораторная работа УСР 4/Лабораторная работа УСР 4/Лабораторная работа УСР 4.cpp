#include <iostream>
using namespace std;

int main() {
    setlocale(0, "");
    int r;
    int n;
    cout << "Введите размер массива: ";
    cin >> r;
    int *arr = new int[r];


    cout << "Введите сдвиг: ";
    cin >> n;


    cout << "Введите Массив " << endl;
        for(int i =0; i < r; i++) {
            cin >> arr[i];
        }

        
    cout << "Сдвинутые элементы: ";
        for(int i =0; i < r-n; i++) {
            cout << arr[i+n] << " ";
    }


    delete[] arr;
    cout << endl;
}