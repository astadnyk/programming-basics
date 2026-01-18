/*
Написати код, який би виконував функцію розрахунку алгоритму завдання: 
y = {
        1.7 cos^2(x)    x ≤ 1       a = 5.1
        (x − 4)^2 + a   1 < x < 2
        5tg(x)          x ≥ 2
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x, y, a = 5.1;

    cout << "Введіть значення x: ";
    cin >> x;
        
    if (x <= 1) {
        y = 1.7 * pow(cos(x), 2);
    } 
    else if (x < 2) {
        y = pow(x - 4, 2) + a;
    } 
    else {
        y = 5 * tan(x);
    }

    cout << "-----------------------" << endl;
    cout << "Результат y = " << y << endl;
    cout << "-----------------------" << endl;

    return 0;
}
