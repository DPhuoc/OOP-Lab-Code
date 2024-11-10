#include <iostream>
#include <cmath> 
#include "donthuc.h"
using namespace std;

// Constructor
DonThuc::DonThuc(double h, int b) : heSo(h), bac(b) {}

double DonThuc::tinhGiaTri(double x) {
    return heSo * pow(x, bac);
}

int DonThuc::layBac() const {
    return bac;
}

double DonThuc::layHeSo() const {
    return heSo;
}

void DonThuc::ganHeSo(double h) {
    heSo = h;
}

void DonThuc::ganBac(int b) {
    bac = b;
}

ostream& operator<<(ostream &out, const DonThuc &d) {
    out << d.heSo << "x^" << d.bac;
    return out;
}