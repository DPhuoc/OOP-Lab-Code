#pragma once
#include <string>
using namespace std;

class NhanVien {
protected:
    string MSNV;
    string TEN;
    long long luongCB;

public:
    NhanVien();
    NhanVien(const string& msnv, const string& ten, long long luongCB);

    virtual ~NhanVien() {}
    virtual long long TienThuong() const = 0;
    virtual void Nhap();
    virtual void Xuat() const;
};