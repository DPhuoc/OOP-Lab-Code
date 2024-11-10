#include "LapTrinhVien.h"
#include <iostream>

using namespace std;

LapTrinhVien::LapTrinhVien(string ma, string ten, int t, string sdt, string mail, long long luong, int gioOvertime)
    : NhanVien(ma, ten, t, sdt, mail, luong), overTime(gioOvertime) {}

void LapTrinhVien::nhap() {
    cout << "Nhap ma nhan vien: ";
    cin >> maNV;
    cout << "Nhap ho ten: ";
    cin.ignore();
    getline(cin, hoTen);
    cout << "Nhap tuoi: ";
    cin >> tuoi;
    cout << "Nhap so dien thoai: ";
    cin >> SDT;
    cout << "Nhap email: ";
    cin >> email;
    cout << "Nhap luong co ban: ";
    cin >> luongCB;
    cout << "Nhap so gio overtime: ";
    cin >> overTime;
}

void LapTrinhVien::xuat() const {
    cout << "---------------------" << maNV << "------------------------" << endl;
    cout << "Ho ten: " << hoTen << endl;
    cout << "Tuoi: " << tuoi << endl;
    cout << "So dien thoai: " << SDT << endl;
    cout << "Email: " << email << endl;
    cout << "Luong co ban: " << luongCB << endl;
    cout << "So gio overtime: " << overTime << endl;
    cout << "Luong thang: " << tinhLuong() << endl;
}

long long LapTrinhVien::tinhLuong() const {
    return luongCB + overTime * 200000; 
}
