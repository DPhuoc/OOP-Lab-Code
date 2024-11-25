#include "KySu.h"
#include <iostream>

KySu::KySu() : NhanVien(), gioLamThem(0) {}

KySu::KySu(const string& msnv, const string& ten, long long luongCB, long long gio) : NhanVien(msnv, ten, luongCB), gioLamThem(gio) {}

long long KySu::TienThuong() const {
    return gioLamThem * 100000;
}

void KySu::Nhap() {
    NhanVien::Nhap();
    cout << "Nhap so gio lam them: ";
    cin >> gioLamThem;
}

void KySu::Xuat() const {
    cout << "---------------- Ky Su --------------\n";
    NhanVien::Xuat();
}