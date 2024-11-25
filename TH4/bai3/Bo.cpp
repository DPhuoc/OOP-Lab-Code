#include "Bo.h"

Bo::Bo() : GiaSuc() {}

Bo::Bo(long long soluong) : GiaSuc(soluong, "Moo Moo") {}

long long Bo::sinhCon() const {
    return rand() % (soLuong / 2);
}

long long Bo::choSua() const {
    long long tongSua;
    for (int i = 0; i < soLuong; i++) {
        tongSua += rand() % 21;
    }    
    return tongSua;
}