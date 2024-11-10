#ifndef PHANSO_H
#define PHANSO_H

class PhanSo {

private:
    int tuso;
    int mauso;

public:
    PhanSo(int t = 0, int m = 1);
    PhanSo(const PhanSo &p);
    int LayTu();
    int LayMau();
    void GanTu(int t);
    void GanMau(int m);
    void Nhap();
    void Xuat();
    bool operator > (PhanSo);
    PhanSo operator + (PhanSo);
    PhanSo operator - (PhanSo);
};

#endif

