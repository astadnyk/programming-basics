/*
Для заданої матриці довільної вимірності визначити скалярний добуток 
рядка з найбільшим елементом на стовпчик та найменшим елементом.
Завдання зробити з використанням функцій. Масиви НЕ РОБИТИ
ГЛОБАЛЬНИМИ. Використати динамічні масиви.
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

// 1. Функція створення та заповнення динамічного масиву
// Повертає вказівник на вказівник (int**), що є адресою нашого масиву в пам'яті
int** createMatrix(int n) {
    // Виділення пам'яті під масив вказівників (рядки)
    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        // Виділення пам'яті під кожен рядок (стовпці)
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 100; // Числа в діапазоні від 0 до 99
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

// 4. Функція пошуку стовпця з мінімальним елементом
int findMinCol(int** matrix, int n) {
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

// 5. Функція обчислення скалярного добутку
long long calcScalarProduct(int** matrix, int n, int row, int col) {
    long long sum = 0;
    // Скалярний добуток: сума добутків відповідних елементів
    for (int k = 0; k < n; k++) {
        sum += matrix[row][k] * matrix[k][col];
    }
    return sum;
}

// 6. Функція звільнення пам'яті динамічного масиву
void deleteMatrix(int** matrix, int n) {
    // Спочатку видаляємо кожен окремий рядок
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    // Потім видаляємо масив вказівників на ці рядки
    delete[] matrix;
}

int main() {
    srand(time(NULL));

    int n;
    // Цикл перевірки коректності введення
    do{
        cout << "Введіть розмір масиву: ";
        cin >> n;
        if (n <= 0) {
            cout << ">>> Помилка: Розмір масиву має бути більшим за 0 !" << endl;
            cout << "--------------------------------------------------" << endl;
        }

    }while( n <= 0);
    
    // Створення матриці
    int** matrix = createMatrix(n);
    
    // Вивід матриці
    printMatrix(matrix, n);
    
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
    
    // Очищення пам'яті перед завершенням програми
    deleteMatrix(matrix, n);

    return 0;
}