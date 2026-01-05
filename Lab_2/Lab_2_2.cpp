#include <iostream>
using namespace std;

int main() {
    double number;
    double res1 = 1;
    double res2 = 1;

    cout << "Введіть по черзі 10 чисел." << endl;
    cout << "--------------------------------" << endl;

    for (int i = 1; i <= 10; i++) {
        cout << "Введіть число #" << i << ": ";
        cin >> number;
        
        if (i <= 5) {
            res1 = res1 * number;
        }
        else if (i >= 7) {
            res2 = res2 * number;
        }
    }

    cout << "--------------------------------" << endl;
    cout << "Добуток перших п'яти чисел: " << res1 << endl;
    cout << "Добуток останніх чотирьох чисел: " << res2 << endl;
    cout << "--------------------------------" << endl;

    return 0;
}