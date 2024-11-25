#include "QuanLy.h"
#include <iostream>

QuanLy::QuanLy() : NhanVien(), tyLeThuong(0) {}

QuanLy::QuanLy(const string& msnv, const string& ten, long long luongCB, float tyLe) : NhanVien(msnv, ten, luongCB), tyLeThuong(tyLe) {}

long long QuanLy::TienThuong() const {
    return luongCB * tyLeThuong;
}

void QuanLy::Nhap() {
    NhanVien::Nhap();
    cout << "Nhap ty le thuong: ";
    cin >> tyLeThuong;
}

void QuanLy::Xuat() const {
    cout << "--------------- Quan Ly ------------\n";
    NhanVien::Xuat();
}