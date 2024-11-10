#include "PhanSo.h"
#include <algorithm>

PhanSo::PhanSo() : iTu(0), iMau(1) {}

PhanSo::PhanSo(int Tu, int Mau) : iTu(Tu), iMau(Mau) {
    simplify();
}

void PhanSo::simplify() {
    int gcd = __gcd(iTu, iMau);
    iTu /= gcd;
    iMau /= gcd;
    if (iMau < 0) { 
        iTu = -iTu;
        iMau = -iMau;
    }
}

PhanSo doubleToFraction(double real) {
    int tu = static_cast<int>(real * 100); 
    int mau = 100;
    return PhanSo(tu, mau);
}


PhanSo PhanSo::operator+(const PhanSo& other) {
    int Tu = iTu * other.iMau + other.iTu * iMau;
    int Mau = iMau * other.iMau;
    return PhanSo(Tu, Mau);
}

PhanSo PhanSo::operator-(const PhanSo& other) {
    int Tu = iTu * other.iMau - other.iTu * iMau;
    int Mau = iMau * other.iMau;
    return PhanSo(Tu, Mau);
}

PhanSo PhanSo::operator*(const PhanSo& other) {
    int Tu = iTu * other.iTu;
    int Mau = iMau * other.iMau;
    return PhanSo(Tu, Mau);
}

PhanSo PhanSo::operator/(const PhanSo& other) {
    int Tu = iTu * other.iMau;
    int Mau = iMau * other.iTu;
    return PhanSo(Tu, Mau);
}

bool PhanSo::operator==(const PhanSo& other) {
    return iTu * other.iMau == iMau * other.iTu;
}

bool PhanSo::operator!=(const PhanSo& other) {
    return !(*this == other);
}

bool PhanSo::operator>=(const PhanSo& other) {
    return iTu * other.iMau >= iMau * other.iTu;
}

bool PhanSo::operator<=(const PhanSo& other) {
    return iTu * other.iMau <= iMau * other.iTu;
}

bool PhanSo::operator>(const PhanSo& other) {
    return iTu * other.iMau > iMau * other.iTu;
}

bool PhanSo::operator<(const PhanSo& other) {
    return iTu * other.iMau < iMau * other.iTu;
}

PhanSo PhanSo::operator+(double real) {
    PhanSo realFraction = doubleToFraction(real);
    return *this + realFraction;
}

PhanSo PhanSo::operator-(double real) {
    PhanSo realFraction = doubleToFraction(real);
    return *this - realFraction;
}

PhanSo PhanSo::operator*(double real) {
    PhanSo realFraction = doubleToFraction(real);
    return *this * realFraction;
}

PhanSo PhanSo::operator/(double real) {
    PhanSo realFraction = doubleToFraction(real);
    return *this / realFraction;
}

istream& operator>>(istream& in, PhanSo& ps) {
    cout << "Nhap tu so: ";
    in >> ps.iTu;
    cout << "Nhap mau so: ";
    in >> ps.iMau;
    ps.simplify();
    return in;
}

ostream& operator<<(ostream& out, const PhanSo& ps) {
    if (ps.iMau == 1) out << ps.iTu;
    else out << ps.iTu << "/" << ps.iMau;
    return out;
}
