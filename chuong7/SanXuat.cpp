#include "SanXuat.h"
#include <iostream>
#include <iomanip> 
using namespace std;

SanXuat::SanXuat(const string& ten, const string& ngay, float luongCB, int soSP)
    : NhanVien(ten, ngay, luongCB), soSanPham(soSP) {}

float SanXuat::tinhLuong() const {
    return luongCB + soSanPham * 2000;
}

void SanXuat::nhap() {
    NhanVien::nhap();
    cout << "Nhap so san pham: ";
    cin >> soSanPham;
}

void SanXuat::xuat() const {
    NhanVien::xuat();
    cout << "So san pham: " << soSanPham << "\nLuong: " << fixed << setprecision(2) << tinhLuong() << endl;
}
