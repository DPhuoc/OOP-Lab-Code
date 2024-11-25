#include "GiaSuc.h"

GiaSuc::GiaSuc() : soLuong(0), tiengKeu("") {}

GiaSuc::GiaSuc(long long soluong, string tiengkeu) : soLuong(soluong), tiengKeu(tiengkeu) {}

void GiaSuc::keu() const {
    for (int i = 0; i < soLuong; i++) {
        cout << tiengKeu << endl;
    }
}

long long GiaSuc::getSoLuong() const {
    return soLuong;
}