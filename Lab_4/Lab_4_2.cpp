/*
Задано масив A (N). Перетворити цей масив за правилом: парні елементи
поділити на середньоарифметичне елементів вхідного масиву, а непарні
вхідного масиву залишити без змін.
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(NULL));

    int n;
    // Цикл перевірки коректності введення
    do{
        cout << "Введіть кількість елементів масиву (N): ";
        cin >> n;
        if (n <= 0) {
            cout << ">>> Помилка: Розмір масиву має бути більшим за 0 !" << endl;
            cout << "-----------------------" << endl;
        }

    }while(n <= 0);
    
    // 1. ВИДІЛЕННЯ ПАМ'ЯТІ
    double* A = new double[n];
    double sum = 0; // Змінна для накопичення суми елементів

    cout << "Згенерований масив:\n";
    for (int i = 0; i < n; i++) {
        // Генеруємо числа від 1 до 50
        A[i] = 1 + rand() % 50;
        cout << (int)A[i] << "\t";
        sum += A[i];
    }
    cout << endl;

    // Обчислення середнього арифметичного
    double average = sum / n;
    cout << fixed << setprecision(2);
    cout << "Середнє арифметичне = " << average << endl;

    // 2. ОБРОБКА МАСИВУ
    for (int i = 0; i < n; i++) {
        if ((int)A[i] % 2 == 0) {
            // Якщо число парне — ділимо його на середнє арифметичне
            A[i] = A[i] / average;
        }
    }

    cout << "Модифікований масив:\n";
    for (int i = 0; i < n; i++) {
        cout << A[i] << "\t";
    }
    cout << endl;

    // 3. ЗВІЛЬНЕННЯ ПАМ'ЯТІ
    delete[] A;

    return 0;
}