#ifndef DSPHANSO_H
#define DSPHANSO_H

#include "phanso.h"

class DSPhanSo {
private:
    PhanSo* ds; 
    int n;   

public:
    DSPhanSo(int size);  
    ~DSPhanSo();        

    void Nhap();   
    PhanSo TimMax(); 
    PhanSo TinhTong();   
    void Xuat();        
};

#endif