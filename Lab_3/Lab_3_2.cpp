#include <iostream>
#include <cmath>
using namespace std;

bool isPerfectSquare(long long x) {
    if (x < 0) return false;
    long long s = sqrt(x);
    return (s * s == x);
}

bool isFibonacci(int n) {
    long long n_long = n; 
    return isPerfectSquare(5 * n_long * n_long + 4) || 
           isPerfectSquare(5 * n_long * n_long - 4);
}

bool isSquarePlusOne(int n) {
    return isPerfectSquare(n - 1);
}

int* check_prime(int *n_ptr) {
    int n = *n_ptr; 
    if (n < 2) return nullptr; 

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return nullptr;
        }
    }

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

    bool foundAny = false;

    for (int i = 2; i <= n; i++) {
        int *prime_ptr = check_prime(&i);

        if (prime_ptr != nullptr) {
            int val = *prime_ptr;
            
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