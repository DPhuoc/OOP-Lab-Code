#include "ThoiGian.h"

ThoiGian::ThoiGian() : iGio(0), iPhut(0), iGiay(0) {}

ThoiGian::ThoiGian(int Gio, int Phut, int Giay) : iGio(Gio), iPhut(Phut), iGiay(Giay) {}

int ThoiGian::TinhGiay() {
    return iGio * 3600 + iPhut * 60 + iGiay;
}

void ThoiGian::TinhLaiGio(int Giay) {
    iGio = Giay / 3600;
    iPhut = (Giay % 3600) / 60;
    iGiay = Giay % 60;
}

ThoiGian ThoiGian::operator+(int Giay) {
    int totalSeconds = TinhGiay() + Giay;
    ThoiGian newTime;
    newTime.TinhLaiGio(totalSeconds);
    return newTime;
}

ThoiGian ThoiGian::operator-(int Giay) {
    int totalSeconds = TinhGiay() - Giay;
    ThoiGian newTime;
    newTime.TinhLaiGio(totalSeconds);
    return newTime;
}

ThoiGian ThoiGian::operator+(ThoiGian a) {
    int totalSeconds = TinhGiay() + a.TinhGiay();
    ThoiGian newTime;
    newTime.TinhLaiGio(totalSeconds);
    return newTime;
}

ThoiGian ThoiGian::operator-(ThoiGian a) {
    int totalSeconds = TinhGiay() - a.TinhGiay();
    ThoiGian newTime;
    newTime.TinhLaiGio(totalSeconds);
    return newTime;
}

ThoiGian ThoiGian::operator++() {
    int totalSeconds = TinhGiay() + 1;
    ThoiGian newTime;
    newTime.TinhLaiGio(totalSeconds);
    return newTime;
}

ThoiGian ThoiGian::operator--() {
    int totalSeconds = TinhGiay() - 1;
    ThoiGian newTime;
    newTime.TinhLaiGio(totalSeconds);
    return newTime;
}

bool ThoiGian::operator==(ThoiGian a) {
    return TinhGiay() == a.TinhGiay();
}

bool ThoiGian::operator!=(ThoiGian a) {
    return TinhGiay() != a.TinhGiay();
}

bool ThoiGian::operator>=(ThoiGian a) {
    return TinhGiay() >= a.TinhGiay();
}

bool ThoiGian::operator<=(ThoiGian a) {
    return TinhGiay() <= a.TinhGiay();
}

bool ThoiGian::operator>(ThoiGian a) {
    return TinhGiay() > a.TinhGiay();
}

bool ThoiGian::operator<(ThoiGian a) {
    return TinhGiay() < a.TinhGiay();
}

istream& operator>>(istream& in, ThoiGian& tg) {
    cout << "Nhap gio: ";
    in >> tg.iGio;
    cout << "Nhap phut: ";
    in >> tg.iPhut;
    cout << "Nhap giay: ";
    in >> tg.iGiay;
    return in;
}

ostream& operator<<(ostream& out, const ThoiGian& tg) {
    out << tg.iGio << ":" << tg.iPhut << ":" << tg.iGiay;
    return out;
}
