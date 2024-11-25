#include "QuanLy.h"
#include "KySu.h"
#include <iostream>

int main() {
    QuanLy ql;
    KySu ks;

    cout << "Nhap thong tin cho quan ly:\n";
    ql.Nhap();
    cout << "\nNhap thong tin cho ky su:\n";
    ks.Nhap();

    cout << "\nThong tin chi tiet cua quan ly:\n";
    ql.Xuat();
    cout << "\nThong tin chi tiet cua ky su:\n";
    ks.Xuat();

    return 0;
}