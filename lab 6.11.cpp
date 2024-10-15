#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

void Create(int* a, int size, int Low, int High, int i = 0) {
    if (i < size) {
        a[i] = Low + rand() % (High - Low + 1);
        Create(a, size, Low, High, i + 1);
    }
}

void Print(int* a, int size, int i = 0) {
    if (i < size) {
        cout << setw(4) << a[i];
        Print(a, size, i + 1);
    }
    else {
        cout << endl;
    }
}

void PrintCriteria(int* a, int size, int i = 0) {
    if (i == 0) {
        cout << "Елементи, що задовольняють критеріям (додатні або з парними індексами): ";
    }
    if (i < size) {
        if (a[i] > 0 || i % 2 == 0) {
            cout << setw(4) << a[i];
        }
        PrintCriteria(a, size, i + 1);
    }
    else {
        cout << endl;
    }
}

int main() {
    srand((unsigned)time(NULL)); // Ініціалізація генератора випадкових чисел
    const int n = 24;
    int p[n];
    int Low = -10;
    int High = 14;

    Create(p, n, Low, High);
    Print(p, n);
    PrintCriteria(p, n);

    return 0;
}
