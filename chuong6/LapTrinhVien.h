#pragma once

#include "NhanVien.h"

class LapTrinhVien : public NhanVien {
private:
    int overTime;

public:
    LapTrinhVien(string ma, string ten, int t, string sdt, string mail, long long luong, int overTime);
    void nhap() override; 
    void xuat() const override;
    long long tinhLuong() const override; 
};

