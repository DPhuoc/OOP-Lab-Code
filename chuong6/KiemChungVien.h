#pragma once
#include "NhanVien.h"

class KiemChungVien : public NhanVien {
private:
    int numBug; 

public:
    KiemChungVien(string ma, string ten, int t, string sdt, string mail, long long luong, int loiPhatHien);
    void nhap() override; 
    void xuat() const override;
    long long tinhLuong() const override;
};

