#include <iostream>

using namespace std;
int rows, cols;

int arraySum(int* matrix) {
    int sum = 0;
    for (int i = 0;i < cols;i++) {
        sum += matrix[i];
    }
    return sum;
}

int main() {
    setlocale(0, "");
    cout << "Введите количество строк: ";
    cin >> rows;
    cout << "Введите количество столбцов: ";
    cin >> cols;

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    cout << "Введите элементы массива:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    bool isSorted = false;
    while (!isSorted) {
        isSorted = true;

        for (int i = 0; i < rows - 1; i += 2) {
            if (arraySum(matrix[i]) < arraySum(matrix[i + 1])) {
                swap(matrix[i], matrix[i + 1]);
                isSorted = false;
            }
        }

        for (int i = 1; i < rows - 1; i += 2) {
            if (arraySum(matrix[i]) < arraySum(matrix[i + 1])) {
                swap(matrix[i], matrix[i + 1]);
                isSorted = false;
            }
        }
    }


    for (int i = 0;i < rows;i++) {
        cout << arraySum(matrix[i]) << " ";
    }

    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

