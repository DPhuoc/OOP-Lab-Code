#include "QuanLy.h"
#include <iostream>
#include <iomanip> 
using namespace std;

QuanLy::QuanLy(const string& ten, const string& ngay, float luongCB, float heSo, float thuong)
    : NhanVien(ten, ngay, luongCB), heSoChucVu(heSo), thuong(thuong) {}

float QuanLy::tinhLuong() const {
    return luongCB * heSoChucVu + thuong;
}

void QuanLy::nhap() {
    NhanVien::nhap();
    cout << "Nhap he so chuc vu: ";
    cin >> heSoChucVu;
    cout << "Nhap thuong: ";
    cin >> thuong;
}

void QuanLy::xuat() const {
    NhanVien::xuat();
    cout << "He so chuc vu: " << heSoChucVu << "\nThuong: " << thuong << "\nLuong: " << fixed << setprecision(2) << tinhLuong() << endl;
}
