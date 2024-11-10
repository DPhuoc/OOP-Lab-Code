#include "NgayThangNam.h"

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
    switch (month) {
        case 4: case 6: case 9: case 11: return 30;
        case 2: return isLeapYear(year) ? 29 : 28;
        default: return 31;
    }
}

NgayThangNam::NgayThangNam() : iNgay(1), iThang(1), iNam(2000) {}

NgayThangNam::NgayThangNam(int ngay, int thang, int nam) : iNgay(ngay), iThang(thang), iNam(nam) {}

int NgayThangNam::TinhNgay() {
    return *this - NgayThangNam(1, 1, 1);
}

NgayThangNam NgayThangNam::operator + (int ngay) const {
    NgayThangNam result = *this;
    while (ngay > 0) {
        int dayMonth = daysInMonth(result.iThang, result.iNam);
        if (result.iNgay + ngay <= dayMonth) {
            result.iNgay += ngay;
            break;
        } else {
            ngay -= (dayMonth - result.iNgay + 1);
            result.iNgay = 1;
            if (++result.iThang > 12) {
                result.iThang = 1;
                ++result.iNam;
            }
        }
    }
    return result;
}

NgayThangNam NgayThangNam::operator - (int ngay) const {
    NgayThangNam result = *this;
    while (ngay > 0) {
        if (result.iNgay > ngay) {
            result.iNgay -= ngay;
            break;
        } else {
            ngay -= result.iNgay;
            if (--result.iThang < 1) {
                result.iThang = 12;
                --result.iNam;
            }
            result.iNgay = daysInMonth(result.iThang, result.iNam);
        }
    }
    return result;
}

int NgayThangNam::operator-(const NgayThangNam& other) const {
    int days1 = iNgay, days2 = other.iNgay;

    for (int y = 0; y < iNam; y++) days1 += isLeapYear(y) ? 366 : 365;
    for (int m = 1; m < iThang; m++) days1 += daysInMonth(m, iNam);

    for (int y = 0; y < other.iNam; y++) days2 += isLeapYear(y) ? 366 : 365;
    for (int m = 1; m < other.iThang; m++) days2 += daysInMonth(m, other.iNam);

    return days1 - days2;
}

bool NgayThangNam::operator == (const NgayThangNam& other) const {
    return (iNgay == other.iNgay && iThang == other.iThang && iNam == other.iNam);
}

bool NgayThangNam::operator != (const NgayThangNam& other) const {
    return !(*this == other);
}

NgayThangNam& NgayThangNam::operator ++ () {
    *this = *this + 1;
    return *this;
}

NgayThangNam NgayThangNam::operator ++ (int) {
    NgayThangNam temp = *this;
    ++(*this);
    return temp;
}

NgayThangNam& NgayThangNam::operator -- () {
    *this = *this - 1;
    return *this;
}

NgayThangNam NgayThangNam::operator -- (int) {
    NgayThangNam temp = *this;
    --(*this);
    return temp;
}

bool NgayThangNam::operator > (const NgayThangNam& other) const {
    if (iNam > other.iNam) return true;
    if (iNam == other.iNam && iThang > other.iThang) return true;
    return (iNam == other.iNam && iThang == other.iThang && iNgay > other.iNgay);
}

bool NgayThangNam::operator >= (const NgayThangNam& other) const {
    return (*this > other) || (*this == other);
}

bool NgayThangNam::operator <= (const NgayThangNam& other) const {
    return (*this < other) || (*this == other);
}

bool NgayThangNam::operator < (const NgayThangNam& other) const {
    return !(*this >= other);
}

std::istream& operator >> (std::istream& is, NgayThangNam& date) {
    is >> date.iNgay >> date.iThang >> date.iNam;
    return is;
}

std::ostream& operator << (std::ostream& os, const NgayThangNam& date) {
    os << date.iNgay << "/" << date.iThang << "/" << date.iNam;
    return os;
}

