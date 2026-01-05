#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double taylor_cos(double *arg_ptr, double epsilon = 0.00001) {
    double x = *arg_ptr;
    double sum = 1.0;
    double term = 1.0;
    int n = 1;

    while (fabs(term) > epsilon) {
        term = term * (-1.0 * x * x) / ((2 * n - 1) * (2 * n));
        sum += term;
        n++;
    }
    return sum;
}

void calculate_y(double *x_ptr, double *y_ptr, bool *is_defined) {
    double x = *x_ptr;

    if (x >= -3 && x <= 0) {
        double arg1 = 2 + x;
        double arg2 = x * x;

        double cos1 = taylor_cos(&arg1);
        double cos2 = taylor_cos(&arg2);

        *y_ptr = pow(cos1, 2) - cos2;
        *is_defined = true;
    } 
    else if (x >= 2 && x <= 3) {
        double arg1 = 2 * x;
        double arg2 = x;

        double cos1 = taylor_cos(&arg1);
        double cos2 = taylor_cos(&arg2);

        *y_ptr = cos1 * cos2;
        *is_defined = true;
    } 
    else {
        *is_defined = false;
    }
}

int main() {
    double x_start = -3.0;
    double x_end = 3.0;
    double step = 0.5;

    double current_x, result_y;
    bool defined;

    cout << "-----------------------------" << endl;
    cout << "|    x    |   y (Тейлор)    |" << endl;
    cout << "-----------------------------" << endl;

    for (current_x = x_start; current_x <= x_end + step / 100.0; current_x += step) {
        
        calculate_y(&current_x, &result_y, &defined);

        cout << "| " << setw(7) << fixed << setprecision(1) << current_x << " | ";
        
        if (defined) {
            cout << setw(15) << setprecision(7) << result_y << " |" << endl;
        } else {
            cout << "   не визначено |" << endl;
        }
    }

    cout << "----------------------------" << endl;

    return 0;
}