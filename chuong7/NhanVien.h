#pragma once

#include <string>
using namespace std;

class NhanVien {
protected:
    string hoTen;
    string ngaySinh;
    float luongCB;

public:
    NhanVien(const string& ten, const string& ngay, float luongCB);
    virtual ~NhanVien() = default;

    virtual float tinhLuong() const = 0;
    virtual void nhap();
    virtual void xuat() const;

    string getHoTen();
};

