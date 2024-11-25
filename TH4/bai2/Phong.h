#pragma once

class Phong {
protected:
    long long soDem;
    long long giaPhong;
    long long phiDichVu;
    long long phiPhucVu;
    long long DoanhThu() const;

public:
    Phong();
    Phong(long long sodem, long long giaphong, long long dichvu, long long phucvu);

    virtual ~Phong() {};
    long long DoanhThu();
};