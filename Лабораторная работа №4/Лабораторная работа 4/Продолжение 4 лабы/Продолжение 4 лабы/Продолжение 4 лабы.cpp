#include <iostream>
using namespace std;

int main() {
    setlocale(0, "");
    int dlinna;
    cin >> dlinna;
    int* massiv = new int[dlinna];


    for(int i = 0; i < dlinna; i++){
        cin >> massiv[i];
    }

    cout << "Введенный массив" << endl;
    for(int i = 0; i < dlinna; i++){
      cout << massiv[i] << " ";
    }

    cout << "массив наоборот" << endl;
    for(int i = dlinna-1; i >= 0; i--) {
        cout << massiv[i] << " ";
    }
    delete[] massiv;
    
}

