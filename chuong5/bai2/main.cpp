#include <iostream>
#include "phanso.h"
#include "phanso.cpp"
#include "dsphanso.h"
#include "dsphanso.cpp"
using namespace std;

int main() {
    int n;
    
    cout << "Nhập số lượng phân số: ";
    cin >> n;

    // Khởi tạo đối tượng DSPhanSo với n phần tử
    DSPhanSo ds(n);

    cout << "Nhập giá trị cho các phân số:\n";
    ds.Nhap();

    cout << "\nCác phân số vừa nhập:\n";
    ds.Xuat();

    PhanSo max = ds.TimMax();
    cout << "\nPhân số lớn nhất là: ";
    max.Xuat();

    PhanSo tong = ds.TinhTong();
    cout << "\nTổng các phân số là: ";
    tong.Xuat();

    return 0;
}