#include <iostream>
#include "ThoiGian.h"

using namespace std;

int main() {
    ThoiGian tg1;
    ThoiGian tg2;

    cout << "Nhap thong tin cho tg1:\n";
    cin >> tg1;
    cout << "Nhap thong tin cho tg2:\n";
    cin >> tg2;

    cout << "\nThoi gian tg1: " << tg1 << endl;
    cout << "Thoi gian tg2: " << tg2 << endl;

    ThoiGian tong = tg1 + tg2;
    cout << "\nTong tg1 + tg2: " << tong << endl;

    ThoiGian hieu = tg1 - tg2;
    cout << "Hieu tg1 - tg2: " << hieu << endl;

    int themGiay;
    cout << "\nNhap so giay de cong vao tg1: ";
    cin >> themGiay;
    ThoiGian tg1ThemGiay = tg1 + themGiay;
    cout << "Thoi gian tg1 sau khi cong " << themGiay << " giay: " << tg1ThemGiay << endl;

    int truGiay;
    cout << "Nhap so giay de tru khoi tg1: ";
    cin >> truGiay;
    ThoiGian tg1TruGiay = tg1 - truGiay;
    cout << "Thoi gian tg1 sau khi tru " << truGiay << " giay: " << tg1TruGiay << endl;

    cout << "\nSo sanh tg1 va tg2:\n";
    cout << "tg1 == tg2: " << (tg1 == tg2 ? "true" : "false") << endl;
    cout << "tg1 != tg2: " << (tg1 != tg2 ? "true" : "false") << endl;
    cout << "tg1 > tg2: " << (tg1 > tg2 ? "true" : "false") << endl;
    cout << "tg1 < tg2: " << (tg1 < tg2 ? "true" : "false") << endl;
    cout << "tg1 >= tg2: " << (tg1 >= tg2 ? "true" : "false") << endl;
    cout << "tg1 <= tg2: " << (tg1 <= tg2 ? "true" : "false") << endl;

    cout << "\nTang tg1 len 1 giay: " << ++tg1 << endl;
    cout << "Giam tg1 xuong 1 giay: " << --tg1 << endl;

    return 0;
}
