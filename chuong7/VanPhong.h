#pragma once
#include "NhanVien.h"
using namespace std;

class VanPhong : public NhanVien {
private:
    int soNgayLamViec;
    float troCap;

public:
    VanPhong(const string& ten, const string& ngay, float luongCB, int ngayLam, float troCap);
    float tinhLuong() const override;
    void nhap() override;
    void xuat() const override;
};

