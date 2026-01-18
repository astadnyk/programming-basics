/*
Увести масив рядків. Рядки містять пробіли на початку та в кінці рядка.
Вирівняти рядки по лівому або по правому полю відповідно до вимог користувача,
вилучивши зайві пробіли.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

// Функція для видалення пробілів на початку та в кінці рядка
string trim(const string& s) {
    // Шукаємо перший символ, який не є пробілом
    size_t first = s.find_first_not_of(' ');
    // Якщо такого символу немає (рядок складається тільки з пробілів або порожній)
    if (string::npos == first) return "";
    // Шукаємо останній символ, який не є пробілом
    size_t last = s.find_last_not_of(' ');
    return s.substr(first, (last - first + 1));
}

int main() {
    int n;
    // Блок введення кількості рядків з перевіркою
    do {
        cout << "Введіть кількість рядків: ";
        cin >> n;
        if (cin.fail() || n <= 0) {
            cin.clear(); // Скидаємо прапорець помилки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаємо буфер
            cout << ">>> Помилка: Введіть ціле число більше за 0!\n";
            n = 0; // Щоб цикл продовжився
        }
    } while (n <= 0);
   
    // Очищення буфера після введення числа (важливо перед getline!)
    cin.ignore();

    // Створення динамічного масива об'єктів string розміром n
    string* lines = new string[n];

    cout << "Введіть рядки (можна з пробілами на початку/в кінці):\n";
    for (int i = 0; i < n; i++) {
        cout << "Рядок " << i + 1 << ": ";
        getline(cin, lines[i]); // Зчитуємо весь рядок разом із пробілами
    }

    // Блок вибору типу вирівнювання
    int choice;
    do {
        cout << "\nОберіть тип вирівнювання:\n1. По лівому краю\n2. По правому краю\nВаш вибір: ";
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Помилка вводу. Спробуйте ще раз.\n";
            choice = 0;
        } else if (choice != 1 && choice != 2) {
            cout << "Оберіть 1 або 2.\n";
        }
    } while (choice != 1 && choice != 2);
    
    // ОБРОБКА ДАНИХ
    int maxLen = 0;
    
    for (int i = 0; i < n; i++) {
        // Видаляємо зайві пробіли
        lines[i] = trim(lines[i]);
        
        // Перевіряємо довжину очищеного рядка
        if (lines[i].length() > maxLen) {
            maxLen = lines[i].length();
        }
    }

    // ВИВЕДЕННЯ РЕЗУЛЬТАТУ
    cout << "\nРезультат:\n";
    cout << string(maxLen + 4, '-') << endl;

    for (int i = 0; i < n; i++) {
        if (choice == 1) {
            // Вирівнювання по лівому краю
            cout << left << lines[i] << endl;
        } else {
            // Вирівнювання по правому краю
            cout << right << setw(maxLen) << lines[i] << endl;
        }
    }
    cout << string(maxLen + 4, '-') << endl;

    // ЗВІЛЬНЕННЯ ПАМ'ЯТІ
    delete[] lines;

    return 0;
}