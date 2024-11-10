#include "KiemChungVien.h"
#include <iostream>

using namespace std;

KiemChungVien::KiemChungVien(string ma, string ten, int t, string sdt, string mail, long long luong, int loiPhatHien)
    : NhanVien(ma, ten, t, sdt, mail, luong), numBug(loiPhatHien) {}

void KiemChungVien::nhap() {
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
    cout << "Nhap so loi phat hien: ";
    cin >> numBug;
}

void KiemChungVien::xuat() const {
    cout << "------------------------" << maNV << "------------------------" << endl;
    cout << "Ho ten: " << hoTen << endl;
    cout << "Tuoi: " << tuoi << endl;
    cout << "So dien thoai: " << SDT << endl;
    cout << "Email: " << email << endl;
    cout << "Luong co ban: " << luongCB << endl;
    cout << "So loi phat hien: " << numBug << endl;
    cout << "Luong thang: " << tinhLuong() << endl;
}

long long KiemChungVien::tinhLuong() const {
    return luongCB + numBug * 50000; 
}
