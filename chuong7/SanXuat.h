#pragma once
#include "NhanVien.h"

class SanXuat : public NhanVien {
private:
    int soSanPham;

public:
    SanXuat(const string& ten, const string& ngay, float luongCB, int soSP);
    float tinhLuong() const override;
    void nhap() override;
    void xuat() const override;
};

