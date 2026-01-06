#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_SIZE = 100; // Максимальний розмір статичного масиву

// 1. Функція створення та заповнення статичного масиву
void fillMatrix(int matrix[][MAX_SIZE], int n) {
    cout << "\nЗгенерована матриця:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 100;
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}

// 2. Функція пошуку рядка з максимальним елементом
int findMaxRow(int matrix[][MAX_SIZE], int n) {
    int maxVal = matrix[0][0];
    int maxRow = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
                maxRow = i;
            }
        }
    }
    return maxRow;
}

// 3. Функція пошуку стовпця з мінімальним елементом
int findMinCol(int matrix[][MAX_SIZE], int n) {
    int minVal = matrix[0][0];
    int minCol = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] < minVal) {
                minVal = matrix[i][j];
                minCol = j;
            }
        }
    }
    return minCol;
}

// 4. Функція обчислення скалярного добутку
long long calcScalarProduct(int matrix[][MAX_SIZE], int n, int row, int col) {
    long long sum = 0;
    for (int k = 0; k < n; k++) {
        sum += matrix[row][k] * matrix[k][col];
    }
    return sum;
}

int main() {
    srand(time(NULL));

    int n;
    do{
        cout << "Введіть розмір масиву (до " << MAX_SIZE << "): ";
        cin >> n;
        if (n <= 0) {
            cout << ">>> Помилка: Розмір масиву має бути більшим за 0 !" << endl;
            cout << "--------------------------------------------------" << endl;
        }
        else if (n > MAX_SIZE) {
            cout << ">>> Помилка: Розмір масиву не може перевищувати " << MAX_SIZE << " !" << endl;
            cout << "--------------------------------------------------" << endl;
        }

    }while(n > MAX_SIZE || n <= 0);
    int matrix[MAX_SIZE][MAX_SIZE]; // Локальний статичний масив

    fillMatrix(matrix, n);
    
    int rowIdx = findMaxRow(matrix, n);
    int colIdx = findMinCol(matrix, n);

    cout << "\n------------------------------------" << endl;
    cout << "Max елемент знаходиться у рядку: " << rowIdx << endl;
    cout << "Min елемент знаходиться у стовпці: " << colIdx << endl;

    cout << "\n------------------------------------" << endl;
    long long result = calcScalarProduct(matrix, n, rowIdx, colIdx);
    cout << "Скалярний добуток становить: " << result << endl;

    return 0;
}
