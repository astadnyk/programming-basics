#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// 1. Функція створення та заповнення динамічного масиву
int** createMatrix(int n) {
    // Виділення пам'яті під масив вказівників (рядки)
    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        // Виділення пам'яті під кожен рядок (стовпці)
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
    return matrix;
}

// 2. Функція виводу матриці
void printMatrix(int** matrix, int n) {
    cout << "\nЗгенерована матриця:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}

// 3. Функція пошуку рядка з максимальним елементом
int findMaxRow(int** matrix, int n) {
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

// 4. Функція пошуку стовпця з мінімальним елементом
int findMinCol(int** matrix, int n) {
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

// 5. Функція обчислення скалярного добутку
long long calcScalarProduct(int** matrix, int n, int row, int col) {
    long long sum = 0;
    for (int k = 0; k < n; k++) {
        sum += matrix[row][k] * matrix[k][col];
    }
    return sum;
}

// 6. Функція звільнення пам'яті динамічного масиву
void deleteMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    srand(time(NULL));

    int n;
    do{
        cout << "Введіть розмір масиву: ";
        cin >> n;
        if (n <= 0) {
            cout << ">>> Помилка: Розмір масиву має бути більшим за 0 !" << endl;
            cout << "--------------------------------------------------" << endl;
        }

    }while( n <= 0);

    int** matrix = createMatrix(n);
    printMatrix(matrix, n);
    
    int rowIdx = findMaxRow(matrix, n);
    int colIdx = findMinCol(matrix, n);

    cout << "\n------------------------------------" << endl;
    cout << "Max елемент знаходиться у рядку: " << rowIdx << endl;
    cout << "Min елемент знаходиться у стовпці: " << colIdx << endl;

    cout << "\n------------------------------------" << endl;
    long long result = calcScalarProduct(matrix, n, rowIdx, colIdx);
    cout << "Скалярний добуток становить: " << result << endl;

    deleteMatrix(matrix, n);

    return 0;
}