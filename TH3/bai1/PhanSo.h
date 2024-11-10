#pragma once
#include <iostream>
using namespace std;

class PhanSo {
private:
    int iTu;
    int iMau;

    void simplify();

public:
    PhanSo();
    PhanSo(int Tu, int Mau);

    PhanSo operator+(const PhanSo& other);
    PhanSo operator-(const PhanSo& other);
    PhanSo operator*(const PhanSo& other);
    PhanSo operator/(const PhanSo& other);

    bool operator==(const PhanSo& other);
    bool operator!=(const PhanSo& other);
    bool operator>=(const PhanSo& other);
    bool operator<=(const PhanSo& other);
    bool operator>(const PhanSo& other);
    bool operator<(const PhanSo& other);

    PhanSo operator+(double real);
    PhanSo operator-(double real);
    PhanSo operator*(double real);
    PhanSo operator/(double real);

    friend istream& operator>>(istream& in, PhanSo& ps);
    friend ostream& operator<<(ostream& out, const PhanSo& ps);
};
