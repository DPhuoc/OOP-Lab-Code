#include <iostream>
#include "phanso.h"
using namespace std;

int UCLN(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

PhanSo::PhanSo(int t, int m) {
    tuso = t;
    if (m == 0) {
        cout << "Mẫu số không được bằng 0. Đã đặt mẫu số thành 1." << endl;
        mauso = 1;
    } else {
        mauso = m;
    }
    int uoc = UCLN(tuso, mauso);
    tuso /= uoc;
    mauso /= uoc;
}

PhanSo::PhanSo(const PhanSo &p) {
    tuso = p.tuso;
    mauso = p.mauso;
}

int PhanSo::LayTu() {
    return tuso;
}

int PhanSo::LayMau() {
    return mauso;
}

void PhanSo::GanTu(int t) {
    tuso = t;
}

void PhanSo::GanMau(int m) {
    if (m == 0) {
        cout << "Mẫu số không được bằng 0. Đã đặt mẫu số thành 1." << endl;
        mauso = 1;
    } else {
        mauso = m;
    }
}

void PhanSo::Nhap() {
    cout << "Nhập tử số: ";
    cin >> tuso;
    cout << "Nhập mẫu số: ";
    cin >> mauso;
    if (mauso == 0) {
        cout << "Mẫu số không được bằng 0. Đã đặt mẫu số thành 1." << endl;
        mauso = 1;
    }
    int uoc = UCLN(tuso, mauso);
    tuso /= uoc;
    mauso /= uoc;
}

void PhanSo::Xuat() {
    if (mauso == 1) {
        cout << tuso << endl;
    } else {
        cout << tuso << "/" << mauso << endl;
    }
}

bool PhanSo::operator > (PhanSo p) {
    return (tuso * p.mauso > mauso * p.tuso);
}

PhanSo PhanSo::operator + (PhanSo p) {
    int tuMoi = tuso * p.mauso + mauso * p.tuso;
    int mauMoi = mauso * p.mauso;
    return PhanSo(tuMoi, mauMoi);
}

PhanSo PhanSo::operator - (PhanSo p) {
    int tuMoi = tuso * p.mauso - mauso * p.tuso;
    int mauMoi = mauso * p.mauso;
    return PhanSo(tuMoi, mauMoi);
}