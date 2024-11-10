#include <iostream>
#include <iomanip>
#include "LapTrinhVien.h"
#include "KiemChungVien.h"

using namespace std;

int main() {
    const int MAX_NHANVIEN = 100;
    NhanVien* danhSachNhanVien[MAX_NHANVIEN];
    int soLuongNhanVien = 0;

    while (true) {
        if (soLuongNhanVien >= MAX_NHANVIEN) {
            cout << "Danh sach nhan vien da day!" << endl;
            break;
        }

        int loaiNhanVien;
        cout << "Nhap loai nhan vien (1: Lap trinh vien, 2: Kiem chung vien, 0: Thoat): ";
        cin >> loaiNhanVien;

        if (loaiNhanVien == 0) {
            break;
        }

        switch (loaiNhanVien) {
            case 1:
                danhSachNhanVien[soLuongNhanVien++] = new LapTrinhVien("", "", 0, "", "", 0, 0);
                break;
            case 2:
                danhSachNhanVien[soLuongNhanVien++] = new KiemChungVien("", "", 0, "", "", 0, 0);
                break;
            default:
                cout << "Loai nhan vien khong hop le!" << endl;
                continue;
        }

        danhSachNhanVien[soLuongNhanVien - 1]->nhap();
    }

    cout << "\nDanh sach nhan vien:\n";
    for (int i = 0; i < soLuongNhanVien; ++i) {
        danhSachNhanVien[i]->xuat();
    }

    double tongLuong = 0;
    for (int i = 0; i < soLuongNhanVien; ++i) {
        tongLuong += danhSachNhanVien[i]->getLuong();
    }
    double luongTrungBinh = tongLuong / soLuongNhanVien;

    cout << "\nLuong trung binh: " << fixed << setprecision(2) << luongTrungBinh << endl;

    cout << "\nDanh sach nhan vien co luong thap hon luong trung binh:\n";
    for (int i = 0; i < soLuongNhanVien; ++i) {
        if (danhSachNhanVien[i]->getLuong() < luongTrungBinh) {
            danhSachNhanVien[i]->xuat();
        }
    }

    for (int i = 0; i < soLuongNhanVien; ++i) {
        delete danhSachNhanVien[i];
    }

    return 0;
}
