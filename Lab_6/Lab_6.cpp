#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <limits>

using namespace std;

// 1. Функція для видалення пробілів на початку та в кінці рядка
string trim(const string& s) {
    size_t first = s.find_first_not_of(' ');
    if (string::npos == first) return "";
    size_t last = s.find_last_not_of(' ');
    return s.substr(first, (last - first + 1));
}

// 2. Функція для знаходження максимальної довжини рядка в масиві
int getMaxLength(const vector<string>& arr) {
    int maxL = 0;
    for (const string& s : arr) {
        if (s.length() > maxL) maxL = s.length();
    }
    return maxL;
}

// 3. Основна функція обробки та виведення
void processAndPrint(vector<string>& arr, int choice) {
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = trim(arr[i]);
    }

    int maxLen = getMaxLength(arr);
    cout << "\nРезультат обробки:\n";
    cout << string(maxLen, '-') << endl;

    for (const string& s : arr) {
        if (choice == 1) {
            cout << s << endl;
        } else {
            cout << setw(maxLen) << s << endl;
        }
    }
    cout << string(maxLen, '-') << endl;
}

int main() {
    int n;
    do {
        cout << "Введіть кількість рядків: ";
        cin >> n;
        cin.ignore();
        if (n <= 0) {
            cout << ">>> Помилка: Введіть ціле число більше за 0 !\n";
        }
    } while (n <= 0);

    vector<string> lines(n);
    for (int i = 0; i < n; i++) {
        cout << "Рядок " << i + 1 << ": ";
        getline(cin, lines[i]);
    }
   

    int choice;
    do {
        cout << "\nОберіть тип вирівнювання:\n1. По лівому краю\n2. По правому краю\nВаш вибір: ";
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Помилка вводу. Спробуйте ще раз.\n";
            choice = 0;
        } else if (choice != 1 && choice != 2) {
            cout << "Оберіть 1 або 2.\n";
        }
    } while (choice != 1 && choice != 2);
    
    processAndPrint(lines, choice);

    return 0;
}