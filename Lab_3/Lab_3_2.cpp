/*
Скласти програму для знаходження всіх простих чисел із діапазону [2,n],
які є числами послідовності Фібоначчі або числами виду q^2 + 1, 
де q – ціле число. Для обчислення простих чисел використати функцію,
яка повертає значення типу покажчик на цілий тип та приймає покажчики.
*/

#include <iostream>
#include <cmath>
using namespace std;

// Перевірка, чи є число повним квадратом
bool isPerfectSquare(long long x) {
    if (x < 0) return false;
    long long s = sqrt(x);
    return (s * s == x);
}

// Перевірка на належність до послідовності Фібоначчі
bool isFibonacci(int n) {
    long long n_long = n; 
    return isPerfectSquare(5 * n_long * n_long + 4) || 
           isPerfectSquare(5 * n_long * n_long - 4);
}

// Перевірка на вигляд q^2 + 1
bool isSquarePlusOne(int n) {
    return isPerfectSquare(n - 1);
}

// Приймає вказівник на число (int *n_ptr)
// Повертає вказівник на це ж число, якщо воно просте, або nullptr, якщо ні
int* check_prime(int *n_ptr) {
    int n = *n_ptr; // Розіменування вказівника, щоб отримати саме число
    
    if (n < 2) return nullptr; 

    // Перевірка на простоту методом перебору дільників до кореня з n
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            // Якщо знайшли дільник — число складене, повертаємо "порожній" вказівник
            return nullptr; 
        }
    }
    // Якщо дільників не знайдено — число просте
    // Повертаємо ту саму адресу, яку отримали на вході
    return n_ptr;
}

int main() {
    int n;
    cout << "Введіть верхню межу діапазону n: ";
    cin >> n;

    cout << "\nРезультати пошуку в діапазоні [2, " << n << "]:" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "Прості числа, які є Фібоначчі АБО мають вигляд q^2 + 1: " << endl;
    cout << "--------------------------------------------------------" << endl;

    bool foundAny = false; // Прапорець, щоб знати, чи знайшли ми хоч щось

    for (int i = 2; i <= n; i++) {
        // Перевірка на простоту
        int *prime_ptr = check_prime(&i);

        // Перевірка результату функції
        if (prime_ptr != nullptr) {
            int val = *prime_ptr;
            // Перевірка додаткових умов
            if (isFibonacci(val) || isSquarePlusOne(val)) {
                cout << val << " ";
                foundAny = true;
            }
        }
    }
    
    if (!foundAny) {
        cout << "Таких чисел не знайдено.";
    }
    
    cout << "\n--------------------------------------------------------" << endl;

    return 0;
}