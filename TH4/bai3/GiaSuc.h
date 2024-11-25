#pragma once

#include <iostream>
#include <string>
using namespace std;

class GiaSuc {
protected:
    long long soLuong;
    string tiengKeu;
public:
    GiaSuc();
    GiaSuc(long long soluong, string tiengkeu);
    virtual ~GiaSuc();

    virtual void keu() const;
    virtual long long sinhCon() const = 0;
    virtual long long choSua() const = 0;

    long long getSoLuong() const;
};