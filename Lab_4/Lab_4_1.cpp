#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int calculate(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    srand(time(NULL));

    int n;
    cout << "Введіть кількість елементів (n): ";
    cin >> n;

    vector<int> A(n), B(n), C(n);

    cout << "\nЗгенеровані масиви:\n";
    
    cout << "A:\t";
    for (int i = 0; i < n; i++) {
        A[i] = 1 + rand() % 100;
        cout << A[i] << "\t";
    }
    cout << endl;

    cout << "B:\t";
    for (int i = 0; i < n; i++) {
        B[i] = 1 + rand() % 100;
        cout << B[i] << "\t";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        C[i] = calculate(A[i], B[i]);
    }

    cout << "\nРезультат:\nC:\t";
    for (int x : C) cout << x << "\t";
    cout << endl;

    return 0;
}