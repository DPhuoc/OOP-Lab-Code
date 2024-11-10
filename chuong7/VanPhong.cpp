#include "VanPhong.h"
#include <iostream>
#include <iomanip> 
using namespace std;

VanPhong::VanPhong(const string& ten, const string& ngay, float luongCB, int ngayLam, float troCap)
    : NhanVien(ten, ngay, luongCB), soNgayLamViec(ngayLam), troCap(troCap) {}

float VanPhong::tinhLuong() const {
    return luongCB + soNgayLamViec * 200000 + troCap;
}

void VanPhong::nhap() {
    NhanVien::nhap();
    cout << "Nhap so ngay lam viec: ";
    cin >> soNgayLamViec;
    cout << "Nhap tro cap: ";
    cin >> troCap;
}

void VanPhong::xuat() const {
    NhanVien::xuat();
    cout << "So ngay lam viec: " << soNgayLamViec << "\nTro cap: " << troCap << "\nLuong: " << fixed << setprecision(2) << tinhLuong() << endl;
}
