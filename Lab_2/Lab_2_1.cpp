#include <iostream>
using namespace std;

int main() {
    int n;
    double a, b;
    double h, r;

    cout << "Введіть натуральне число n (кількість кроків): ";
    cin >> n;
    // --- Блок перевірки введення ---
    do {
        cout << "Введіть число a: ";
        cin >> a;
        cout << "Введіть число b: ";
        cin >> b;

        // Перевірка умови
        if (a == b) {
            cout << ">>> Помилка: числа a і b не можуть бути рівними! Спробуйте ще раз." << endl;
            cout << "-----------------------" << endl;
        }

    } while (a == b);
    // --------------------------------
    
    h = (b - a) / n;
    
    cout << "-----------------------" << endl;
    cout << "Крок h = " << h << endl;
    cout << "Послідовність:" << endl;

    for (int i = 1; i <= n; i++) {
        r = a + i * h;
        cout << "r[" << i << "] = " << r << endl;
    }
    cout << "-----------------------" << endl;

    return 0;
}
