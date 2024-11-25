#include "Cuu.h"

Cuu::Cuu() : GiaSuc() {}

Cuu::Cuu(long long soluong) : GiaSuc(soluong, "Be Be") {}

long long Cuu::sinhCon() const {
    return rand() % (soLuong / 2);
}

long long Cuu::choSua() const {
    long long tongSua;
    for (int i = 0; i < soLuong; i++) {
        tongSua += rand() % 11;
    }    
    return tongSua;
}