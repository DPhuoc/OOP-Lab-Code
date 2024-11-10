#include "NhanVien.h"

NhanVien::NhanVien(string ma, string ten, int t, string sdt, string mail, long long luong)
    : maNV(ma), hoTen(ten), tuoi(t), SDT(sdt), email(mail), luongCB(luong) {}

string NhanVien::getHoTen() const {
    return hoTen;
}

double NhanVien::getLuong() const {
    return tinhLuong();
}

NhanVien::~NhanVien() {}
