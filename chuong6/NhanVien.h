#pragma once

#include <iostream>
#include <string>

using namespace std;

class NhanVien {
protected:
    string maNV;
    string hoTen;
    int tuoi;
    string SDT;
    string email;
    long long luongCB;

public:
    NhanVien(string ma, string ten, int t, string sdt, string mail, long long luong);
    virtual void nhap() = 0; 
    virtual void xuat() const = 0; 
    virtual long long tinhLuong() const = 0; 

    string getHoTen() const;
    double getLuong() const;

    virtual ~NhanVien();
};

