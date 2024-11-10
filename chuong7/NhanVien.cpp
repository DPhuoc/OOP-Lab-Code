#include "NhanVien.h"
#include <iostream>
#include <iomanip> 
using namespace std;

NhanVien::NhanVien(const string& ten, const string& ngay, float luongCB)
    : hoTen(ten), ngaySinh(ngay), luongCB(luongCB) {}

void NhanVien::nhap() {
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
    cout << "Nhap ngay sinh: ";
    getline(cin, ngaySinh);
    cout << "Nhap luong co ban: ";
    cin >> luongCB;
}

void NhanVien::xuat() const {
    cout << "-----------------------" << hoTen << "---------------------";
    cout << "\nNgay sinh: " << ngaySinh << "\nLuong co ban: " << fixed << setprecision(2) << luongCB << std::endl;
}

string NhanVien::getHoTen() {
    return hoTen;
}
