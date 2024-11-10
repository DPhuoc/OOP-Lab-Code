#pragma once
#include <iostream>
using namespace std;

class SoPhuc {
private:
    double dThuc;
    double dAo;

public:
    SoPhuc();
    SoPhuc(double thuc, double ao);

    SoPhuc operator+(const SoPhuc& other);
    SoPhuc operator-(const SoPhuc& other);
    SoPhuc operator*(const SoPhuc& other);
    SoPhuc operator/(const SoPhuc& other);
    bool operator==(const SoPhuc& other);
    bool operator!=(const SoPhuc& other);

    SoPhuc operator+(double real);
    SoPhuc operator-(double real);
    SoPhuc operator*(double real);
    SoPhuc operator/(double real);

    friend istream& operator>>(istream& in, SoPhuc& sp);
    friend ostream& operator<<(ostream& out, const SoPhuc& sp);
};
