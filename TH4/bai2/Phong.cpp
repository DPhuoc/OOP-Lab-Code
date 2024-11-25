#include "Phong.h"
#include <iostream>
using namespace std;

Phong::Phong() : soDem(0), giaPhong(0), phiDichVu(0), phiPhucVu(0) {}

Phong::Phong(long long sodem, long long giaphong, long long dichvu, long long phucvu) :
    soDem(sodem), giaPhong(giaphong), phiDichVu(dichvu), phiPhucVu(phucvu) {}

long long Phong::DoanhThu() {
    return soDem * giaPhong + phiDichVu + phiPhucVu;
}


