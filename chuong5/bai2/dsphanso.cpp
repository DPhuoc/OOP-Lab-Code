#include "dsphanso.h"
#include <iostream>
using namespace std;

DSPhanSo::DSPhanSo(int size) {
    n = size;
    ds = new PhanSo[n];
}

DSPhanSo::~DSPhanSo() {
    delete[] ds;
}

void DSPhanSo::Nhap() {
    for (int i = 0; i < n; i++) {
        cout << "Nhập phân số thứ " << i + 1 << ":\n";
        ds[i].Nhap();
    }
}

void DSPhanSo::Xuat() {
    for (int i = 0; i < n; i++) {
        cout << "Phân số thứ " << i + 1 << ": ";
        ds[i].Xuat();
    }
}

PhanSo DSPhanSo::TimMax() {
    PhanSo max = ds[0];
    for (int i = 1; i < n; i++) {
        if (ds[i] > max) {
            max = ds[i];
        }
    }
    return max;
}

PhanSo DSPhanSo::TinhTong() {
    PhanSo tong = ds[0];
    for (int i = 1; i < n; i++) {
        tong = tong + ds[i];
    }
    return tong;
}