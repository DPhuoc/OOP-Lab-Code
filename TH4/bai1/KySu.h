#pragma once
#include "NhanVien.h"

class KySu : public NhanVien {
private:
    long long gioLamThem;

public:
    KySu();
    KySu(const string& msnv, const string& ten, long long luongCB, long long gio);
    
    long long TienThuong() const override;
    void Nhap() override;
    void Xuat() const override;
};