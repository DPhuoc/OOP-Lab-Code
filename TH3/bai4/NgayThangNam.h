#pragma once
#include <iostream>

class NgayThangNam {
private:
    int iNgay;
    int iThang;
    int iNam;

public:
    NgayThangNam();
    NgayThangNam(int nam, int thang, int ngay);

    int TinhNgay();

    NgayThangNam operator + (int ngay) const;
    NgayThangNam operator - (int ngay) const;
    int operator - (const NgayThangNam& other) const;

    NgayThangNam& operator++(); 
    NgayThangNam operator++(int); 
    NgayThangNam& operator--();  
    NgayThangNam operator--(int); 

    bool operator==(const NgayThangNam& other) const;
    bool operator!=(const NgayThangNam& other) const;
    bool operator>=(const NgayThangNam& other) const;
    bool operator<=(const NgayThangNam& other) const;
    bool operator>(const NgayThangNam& other) const;
    bool operator<(const NgayThangNam& other) const;

    friend std::istream& operator>>(std::istream& is, NgayThangNam& date);
    friend std::ostream& operator<<(std::ostream& os, const NgayThangNam& date);
};

bool isLeapYear(int year);
int daysInMonth(int month, int year);