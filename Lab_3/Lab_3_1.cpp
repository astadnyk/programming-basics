/*
Обчислити значення функції у, розвинувши функцію cos(х) у ряд
Тейлора, де x змінюється від -3 до 3 з кроком 0.5.
y = {
        cos^2(2 + x) − cos(x^2),    − 3 ≤ x ≤ 0,
        cos(2 ∗ x) ∗ cos(x),        2 ≤ x ≤ 3.
*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Функція обчислення косинуса через ряд Тейлора
// Приймає вказівник на число (arg_ptr) та точність (epsilon)
double taylor_cos(double *arg_ptr, double epsilon = 0.00001) {
    double x = *arg_ptr; // Розіменовуємо вказівник: отримуємо саме значення x
    double sum = 1.0; 
    double term = 1.0;
    int n = 1;

    while (fabs(term) > epsilon) {
        // Рекурентна формула для ряду Тейлора
        term = term * (-1.0 * x * x) / ((2 * n - 1) * (2 * n));
        sum += term;
        n++;
    }
    return sum;
}

// Функція для обчислення Y згідно з умовою
void calculate_y(double *x_ptr, double *y_ptr, bool *is_defined) {
    double x = *x_ptr;

    // Перша умова: -3 <= x <= 0
    if (x >= -3 && x <= 0) {
        double arg1 = 2 + x;
        double arg2 = x * x;

        // Передаємо адреси змінних (&arg1), бо функція чекає вказівники
        double cos1 = taylor_cos(&arg1);
        double cos2 = taylor_cos(&arg2);

        // Формула: y = cos^2(2 + x) - cos(x^2)
        *y_ptr = pow(cos1, 2) - cos2;
        *is_defined = true;
    } 
    // Друга умова: 2 <= x <= 3
    else if (x >= 2 && x <= 3) {
        double arg1 = 2 * x;
        double arg2 = x;

        double cos1 = taylor_cos(&arg1);
        double cos2 = taylor_cos(&arg2);

        // Формула: y = cos(2*x) * cos(x)
        *y_ptr = cos1 * cos2;
        *is_defined = true;
    } 
    // Якщо x не потрапляє в жоден інтервал
    else {
        *is_defined = false;
    }
}

int main() {
    double x_start = -3.0;
    double x_end = 3.0;
    double step = 0.5;

    double current_x, result_y;
    bool defined; // Прапорець: чи існує y для поточного x

    cout << "-----------------------------" << endl;
    cout << "|    x    |   y (Тейлор)    |" << endl;
    cout << "-----------------------------" << endl;

    for (current_x = x_start; current_x <= x_end + step / 100.0; current_x += step) {
        // Викликаємо функцію, передаючи АДРЕСИ змінних (&)
        calculate_y(&current_x, &result_y, &defined);

        // Виводимо x з точністю 1 знак після коми
        cout << "| " << setw(7) << fixed << setprecision(1) << current_x << " | ";
        
        if (defined) {
            // Якщо функція визначена - виводимо результат
            cout << setw(15) << setprecision(7) << result_y << " |" << endl;
        } else {
            // Якщо ні - пишемо повідомлення
            cout << "   не визначено |" << endl;
        }
    }

    cout << "----------------------------" << endl;

    return 0;
}