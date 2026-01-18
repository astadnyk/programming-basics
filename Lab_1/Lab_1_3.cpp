/*
Написати мовою С/С++ з використанням команд switch case результат виконання умови:
Ввести число з діапазону від 0 до 5. Вивести його написання двома мовами.
*/

#include <iostream>
using namespace std;

int main() {
    int num;
    
    cout << "Введіть число від 0 до 5: ";
    cin >> num;

    switch (num) {
        case 0:
            cout << "Нуль / Zero" << endl;
            break; 
        case 1:
            cout << "Один / One" << endl;
            break;
        case 2:
            cout << "Два / Two" << endl;
            break;
        case 3:
            cout << "Три / Three" << endl;
            break;
        case 4:
            cout << "Чотири / Four" << endl;
            break;
        case 5:
            cout << "П\'ять / Five" << endl;
            break;
        default: 
            cout << "Помилка! Число має бути від 0 до 5." << endl;
    }

    return 0;
}
