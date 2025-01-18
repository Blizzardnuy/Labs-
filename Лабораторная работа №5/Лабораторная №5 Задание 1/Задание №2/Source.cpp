#include <iostream>

using namespace std;
int main() {
    int r, c;
    int* min = new int(INT_MIN);
    int* max = new int(INT_MAX);
    cin >> r >> c;
    int** matrix = new int* [r];
    for (int i = 0; i < r; ++i) {
        matrix[i] = new int[c];
    }
    for (int i = 0; i < r;i++) {
        for (int k = 0; k < c; k++) {
            cin >> matrix[i][k];

            if (matrix[i][k] > *min && matrix[i][k] < 0)
                min = &matrix[i][k];

            if (matrix[i][k] < *max && matrix[i][k] > 0)
                max = &matrix[i][k];
        }
    }
    swap(*min, *max);
    for (int i = 0; i < r; i++) {
        for (int k = 0; k < c; k++) {
            cout << matrix[i][k] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < r; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete min;
    delete max;
}
