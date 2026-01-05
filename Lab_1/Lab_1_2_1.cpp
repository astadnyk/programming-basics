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
    double Y, taxRate;

    if (type == 'A') {
        Y = 100 * fabs(Fi + 3 * x + 50);
        taxRate = 0.10;
    }
    else if (type == 'B') {
        Y = 150 * fabs(Fi + 4 * x + 100);
        taxRate = 0.15;
    }
    else if (type == 'C') {
        Y = 100 * fabs(Fi + 5 * x + 135);
        taxRate = 0.20;
    }
    else {
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
