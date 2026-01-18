/*
Для заданої матриці довільної вимірності визначити скалярний добуток 
рядка з найбільшим елементом на стовпчик та найменшим елементом.
Завдання зробити з використанням функцій. Масиви НЕ РОБИТИ
ГЛОБАЛЬНИМИ. Використати статичні масиви.
*/

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
    // Перебираємо всі елементи матриці
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Якщо знайшли число, більше за поточний максимум
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
                maxRow = i;
            }
        }
    }
    return maxRow; // Повертаємо тільки номер рядка
}

// 3. Функція пошуку стовпця з мінімальним елементом
int findMinCol(int matrix[][MAX_SIZE], int n) {
    int minVal = matrix[0][0];
    int minCol = 0;
    // Перебираємо всі елементи
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Якщо знайшли число, менше за поточний мінімум
            if (matrix[i][j] < minVal) {
                minVal = matrix[i][j];
                minCol = j;
            }
        }
    }
    return minCol; // Повертаємо тільки номер стовпця
}

// 4. Функція обчислення скалярного добутку
long long calcScalarProduct(int matrix[][MAX_SIZE], int n, int row, int col) {
    long long sum = 0;
    // Скалярний добуток: сума добутків відповідних елементів
    for (int k = 0; k < n; k++) {
        sum += matrix[row][k] * matrix[k][col];
    }
    return sum;
}

int main() {
    srand(time(NULL));

    int n;
    // Цикл перевірки коректності введення
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
    
    // Створення матриці
    int matrix[MAX_SIZE][MAX_SIZE]; // Локальний статичний масив
    fillMatrix(matrix, n);
    
    // Пошук індексів
    int rowIdx = findMaxRow(matrix, n);
    int colIdx = findMinCol(matrix, n);

    cout << "\n------------------------------------" << endl;
    cout << "Max елемент знаходиться у рядку: " << rowIdx << endl;
    cout << "Min елемент знаходиться у стовпці: " << colIdx << endl;
    cout << "\n------------------------------------" << endl;
    
    // Обчислення результату
    long long result = calcScalarProduct(matrix, n, rowIdx, colIdx);
    cout << "Скалярний добуток становить: " << result << endl;

    return 0;
}
