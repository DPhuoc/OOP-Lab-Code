#include <iostream>
#include <iomanip>
#include "VanPhong.h"
#include "SanXuat.h"
#include "QuanLy.h"
using namespace std;

const long long MAXN = 1e5 + 1;

NhanVien* arr[MAXN];
int n;

int main() {
    cout << "Nhap so luong nhan vien: "; cin >> n;
    cin.ignore();
    
    for (int i = 0; i < n; ++i) {
        int loaiNhanVien;
        cout << "\nNhap loai nhan vien (1: Van phong, 2: San xuat, 3: Quan ly): ";
        cin >> loaiNhanVien;
        cin.ignore(); 

        switch (loaiNhanVien) {
            case 1:
                arr[i] = new VanPhong("", "", 0, 0, 0);
                arr[i]->nhap();
                break;
            case 2:
                arr[i] = new SanXuat("", "", 0, 0);
                arr[i]->nhap();
                break;
            case 3:
                arr[i] = new QuanLy("", "", 0, 0, 0);
                arr[i]->nhap();
                break;
        }
    }

    for (int i = 0; i < n; ++i) {
        arr[i]->xuat();
    }

    double tongLuong = 0;
    for (int i = 0; i < n; ++i) {
        tongLuong += arr[i]->tinhLuong();
    }

    cout << "\nTong luong cua cong ty: " << fixed << setprecision(2) << tongLuong << " VND" << endl;

    string tenCanTim;
    cin.ignore();
    cout << "\nNhap ten nhan vien can tim: ";
    getline(std::cin, tenCanTim);

    bool timThay = false;
    for (int i = 0; i < n; ++i) {
        if (arr[i]->getHoTen() == tenCanTim) {
            cout << "\nThong tin nhan vien tim thay:\n";
            arr[i]->xuat();
            timThay = true;
        }
    }

    if (!timThay) {
        cout << "Khong tim thay nhan vien co ten \"" << tenCanTim << "\" trong cong ty." << std::endl;
    }

    for (int i = 0; i < n; ++i) {
        delete arr[i];
    }

    return 0;
}
