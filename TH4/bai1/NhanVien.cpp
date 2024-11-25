#include "NhanVien.h"
#include <iostream>
using namespace std;

NhanVien::NhanVien() : MSNV(""), TEN(""), luongCB(0) {}

NhanVien::NhanVien(const string& msnv, const string& ten, long long luongCB) : MSNV(msnv), TEN(ten), luongCB(luongCB) {}

void NhanVien::Nhap() {
    cout << "Nhap ma so nhan vien: ";
    cin >> MSNV;
    cin.ignore();
    cout << "Nhap ten nhan vien: ";
    getline(cin, TEN);
    cout << "Nhap luong co ban: ";
    cin >> luongCB;
}

void NhanVien::Xuat() const {
    cout << "MSNV: " << MSNV << endl;
    cout << "Ten: " << TEN << endl;
    cout << "Luong co ban: " << luongCB << " VND" << endl;
    cout << "Tien Thuong: " << TienThuong() << " VND" << endl;
}