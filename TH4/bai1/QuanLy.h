#pragma once
#include "NhanVien.h"

class QuanLy : public NhanVien {
private:
    float tyLeThuong;

public:
    QuanLy();
    QuanLy(const string& msnv, const string& ten, long long luongCB, float tyLe);

    long long TienThuong() const override;
    void Nhap() override;
    void Xuat() const override;
};