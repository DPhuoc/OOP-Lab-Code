#include <iostream>
#include "donthuc.h"
#include "donthuc.cpp"
#include "dathuc.h"
#include "dathuc.cpp"

using namespace std;

int main() {
    int bac;

    cout << "Nhập bậc của đa thức: ";
    cin >> bac;

    DaThuc dt1(bac);

    cout << "Nhập các hệ số cho đa thức thứ nhất:\n";
    cin >> dt1;

    cout << "Đa thức thứ nhất: " << dt1 << endl;

    double x;
    cout << "Nhập giá trị của x: ";
    cin >> x;
    cout << "Giá trị của đa thức tại x = " << x << " là: " << dt1.tinhGiaTri(x) << endl;

    DaThuc dt2(bac);
    cout << "Nhập các hệ số cho đa thức thứ hai:\n";
    cin >> dt2;

    DaThuc tong = dt1 + dt2;
    cout << "Tổng của hai đa thức: " << tong << endl;

    DaThuc hieu = dt1 - dt2;
    cout << "Hiệu của hai đa thức: " << hieu << endl;

    return 0;
}