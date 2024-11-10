#include <iostream>
#include "complex.h"
#include "complex.cpp"
using namespace std;

int main() {
    Complex a, b;

    cout << "Nhập số phức a:\n";
    cin >> a;
    cout << "Nhập số phức b:\n";
    cin >> b;

    cout << "Số phức a: " << a << endl;
    cout << "Số phức b: " << b << endl;

    Complex sum = a + b;
    cout << "a + b = " << sum << endl;

    Complex diff = a - b;
    cout << "a - b = " << diff << endl;

    Complex prod = a * b;
    cout << "a * b = " << prod << endl;

    Complex quot = a / b;
    cout << "a / b = " << quot << endl;

    if (a == b) {
        cout << "a và b bằng nhau.\n";
    } else {
        cout << "a và b khác nhau.\n";
    }

    return 0;
}