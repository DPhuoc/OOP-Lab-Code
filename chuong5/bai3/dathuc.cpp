#include <iostream>
#include "dathuc.h"
using namespace std;

DaThuc::DaThuc() {
    cacDonThuc.push_back(DonThuc(0, 0));
}

DaThuc::DaThuc(int bac) {
    for (int i = bac; i >= 0; --i) {
        cacDonThuc.push_back(DonThuc(0, i));
    }
}

void DaThuc::nhap() {
    for (size_t i = 0; i < cacDonThuc.size(); ++i) {
        double heSo;
        cout << "Nhập hệ số cho x^" << cacDonThuc[i].layBac() << ": ";
        cin >> heSo;
        cacDonThuc[i].ganHeSo(heSo);
    }
}

// Xuất đa thức
void DaThuc::xuat() {
    for (size_t i = 0; i < cacDonThuc.size(); ++i) {
        cout << cacDonThuc[i];
        if (i < cacDonThuc.size() - 1) {
            cout << " + ";
        }
    }
    cout << endl;
}

double DaThuc::tinhGiaTri(double x) {
    double ketQua = 0;
    for (size_t i = 0; i < cacDonThuc.size(); ++i) {
        ketQua += cacDonThuc[i].tinhGiaTri(x);
    }
    return ketQua;
}

DaThuc DaThuc::operator+(const DaThuc &dt) {
    DaThuc ketQua(*this);
    for (size_t i = 0; i < cacDonThuc.size(); ++i) {
        double heSoMoi = cacDonThuc[i].layHeSo() + dt.cacDonThuc[i].layHeSo();
        ketQua.cacDonThuc[i].ganHeSo(heSoMoi);
    }
    return ketQua;
}

DaThuc DaThuc::operator-(const DaThuc &dt) {
    DaThuc ketQua(*this);
    for (size_t i = 0; i < cacDonThuc.size(); ++i) {
        double heSoMoi = cacDonThuc[i].layHeSo() - dt.cacDonThuc[i].layHeSo();
        ketQua.cacDonThuc[i].ganHeSo(heSoMoi);
    }
    return ketQua;
}

ostream& operator<<(ostream &out, const DaThuc &dt) {
    for (size_t i = 0; i < dt.cacDonThuc.size(); ++i) {
        out << dt.cacDonThuc[i];
        if (i < dt.cacDonThuc.size() - 1) {
            out << " + ";
        }
    }
    return out;
}

istream& operator>>(istream &in, DaThuc &dt) {
    for (size_t i = 0; i < dt.cacDonThuc.size(); ++i) {
        double heSo;
        cout << "Nhập hệ số cho x^" << dt.cacDonThuc[i].layBac() << ": ";
        in >> heSo;
        dt.cacDonThuc[i].ganHeSo(heSo);
    }
    return in;
}