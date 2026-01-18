/*
Задані масиви А, В з n цілих чисел, кількість вводиться з клавіатури.
Побудувати масив С, в якому кожний елемент дорівнює найбільшому
спільному дільнику чисел а, b. Використати алгоритм Евкліда.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Функція для обчислення НСД (Найбільшого Спільного Дільника)
int calculate(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    srand(time(NULL));

    int n;
    cout << "Введіть кількість елементів (n): ";
    cin >> n;
    
    // 1. СТВОРЕННЯ ДИНАМІЧНИХ МАСИВІВ
    int* A = new int[n];
    int* B = new int[n];
    int* C = new int[n];

    cout << "\nЗгенеровані масиви:\n";
    
    // Заповнення та вивід масиву A
    cout << "A:\t";
    for (int i = 0; i < n; i++) {
        A[i] = 1 + rand() % 100;
        cout << A[i] << "\t";
    }
    cout << endl;

    // Заповнення та вивід масиву B
    cout << "B:\t";
    for (int i = 0; i < n; i++) {
        B[i] = 1 + rand() % 100;
        cout << B[i] << "\t";
    }
    cout << endl;

    // ОБРОБКА ДАНИХ
    // Проходимо по кожному елементу масивів
    for (int i = 0; i < n; i++) {
        C[i] = calculate(A[i], B[i]);
    }

    cout << "\nРезультат:\nC:\t";
    for (int i = 0; i < n; i++) {
        cout << C[i] << "\t";
    }
    cout << endl;

    // 2. ЗВІЛЬНЕННЯ ПАМ'ЯТІ
    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}