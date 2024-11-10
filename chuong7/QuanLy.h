#pragma once
#include "NhanVien.h"
using namespace std;

class QuanLy : public NhanVien {
private:
    float heSoChucVu;
    float thuong;

public:
    QuanLy(const string& ten, const string& ngay, float luongCB, float heSo, float thuong);
    float tinhLuong() const override;
    void nhap() override;
    void xuat() const override;
};
