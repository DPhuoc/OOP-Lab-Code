#include <iostream>
#include "matran.h"
#include "matran.cpp"

using namespace std;

int main() {
    int m1, n1, m2, n2;

    cout << "Nhập số dòng và cột của ma trận thứ nhất: ";
    cin >> m1 >> n1;
    MaTran mt1(m1, n1);
    mt1.nhap();

    cout << "Nhập số dòng và cột của ma trận thứ hai: ";
    cin >> m2 >> n2;
    MaTran mt2(m2, n2);
    mt2.nhap();

    cout << "Kết quả cộng hai ma trận:\n";
    MaTran tong = mt1 + mt2;
    cout << tong;

    cout << "Kết quả trừ hai ma trận:\n";
    MaTran hieu = mt1 - mt2;
    cout << hieu;

    if (n1 == m2) {
        cout << "Kết quả nhân hai ma trận:\n";
        MaTran tich = mt1 * mt2;
        cout << tich;
    } else {
        cout << "Không thể nhân hai ma trận vì kích thước không hợp lệ!" << endl;
    }

    return 0;
}