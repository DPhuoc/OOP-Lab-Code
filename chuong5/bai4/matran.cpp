#include "matran.h"
#include <iostream>
#include <cstdlib> 
#include <ctime> 
using namespace std;

MaTran::MaTran(int m, int n) : m(m), n(n), data(m, std::vector<int>(n, 0)) {}

// Nhập ma trận
void MaTran::nhap() {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Nhập phần tử [" << i << "][" << j << "]: ";
            cin >> data[i][j];
        }
    }
}


void MaTran::xuat() const {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}


void MaTran::taoNgauNhien() {
    srand(time(0)); 
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            data[i][j] = rand() % 100; 
        }
    }
}

MaTran MaTran::operator+(const MaTran &mt) const {
    if (!kichThuocHopLe(mt)) {
        cout << "Kích thước hai ma trận không hợp lệ để cộng!" << endl;
        return MaTran(0, 0);
    }

    MaTran ketQua(m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            ketQua.data[i][j] = data[i][j] + mt.data[i][j];
        }
    }
    return ketQua;
}

MaTran MaTran::operator-(const MaTran &mt) const {
    if (!kichThuocHopLe(mt)) {
        cout << "Kích thước hai ma trận không hợp lệ để trừ!" << endl;
        return MaTran(0, 0);
    }

    MaTran ketQua(m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            ketQua.data[i][j] = data[i][j] - mt.data[i][j];
        }
    }
    return ketQua;
}

MaTran MaTran::operator*(const MaTran &mt) const {
    if (n != mt.m) {
        cout << "Kích thước không hợp lệ để nhân ma trận!" << endl;
        return MaTran(0, 0);
    }

    MaTran ketQua(m, mt.n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < mt.n; j++) {
            for (int k = 0; k < n; k++) {
                ketQua.data[i][j] += data[i][k] * mt.data[k][j];
            }
        }
    }
    return ketQua;
}

bool MaTran::kichThuocHopLe(const MaTran &mt) const {
    return (m == mt.m && n == mt.n);
}

ostream& operator<<(ostream &out, const MaTran &mt) {
    for (int i = 0; i < mt.m; i++) {
        for (int j = 0; j < mt.n; j++) {
            out << mt.data[i][j] << " ";
        }
        out << endl;
    }
    return out;
}