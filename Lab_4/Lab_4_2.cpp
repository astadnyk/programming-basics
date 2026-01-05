#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    setlocale(LC_ALL, "");
    srand(time(NULL));

    int n;
    do{
        cout << "Введіть кількість елементів масиву (N): ";
        cin >> n;
        if (n <= 0) {
            cout << ">>> Помилка: Розмір масиву має бути більшим за 0 !" << endl;
            cout << "-----------------------" << endl;
        }

    }while(n <= 0);
    vector<double> A(n);
    double sum = 0;

    cout << "Згенерований масив:\n";
    for (int i = 0; i < n; i++) {
        A[i] = 1 + rand() % 50;
        cout << (int)A[i] << "\t";
        sum += A[i];
    }
    cout << endl;

    double average = sum / n;
    cout << fixed << setprecision(2);
    cout << "Середнє арифметичне = " << average << endl;

    for (int i = 0; i < n; i++) {
        if ((int)A[i] % 2 == 0) {
            A[i] = A[i] / average;
        }
    }

    cout << "Модифікований масив:\n";
    for (int i = 0; i < n; i++) {
        cout << A[i] << "\t";
    }
    cout << endl;

    return 0;
}