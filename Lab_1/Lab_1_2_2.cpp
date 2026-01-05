#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x;
    char type;

    cout << "Введіть значення x: ";
    cin >> x;
    cout << "Введіть тип роботи (A, B, C): ";
    cin >> type;

    double Fi = 13.4 * cos(fabs(4 * sin(x * x - 2.25)));

    double Y =
        (type == 'A') ? 100 * fabs(Fi + 3 * x + 50) :
        (type == 'B') ? 150 * fabs(Fi + 4 * x + 100) :
        (type == 'C') ? 100 * fabs(Fi + 5 * x + 135) : 0;

    double taxRate =
        (type == 'A') ? 0.10 :
        (type == 'B') ? 0.15 :
        (type == 'C') ? 0.20 : 0;

    if (taxRate == 0) {
        cout << "Невірний тип роботи!" << endl;
        return 1;
    }

    double tax = Y * taxRate;
    double pay = Y - tax;

    cout << "-----------------------" << endl;
    cout << "Нарахована сума: " << Y << endl;
    cout << "Податок: " << tax << endl;
    cout << "Сума до сплати: " << pay << endl;
    cout << "-----------------------" << endl;

    return 0;
}
