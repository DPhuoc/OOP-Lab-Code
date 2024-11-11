#include "PhanSo.h"

int main() {
    PhanSo ps1, ps2;

    cout << "Nhap phan so thu nhat:\n";
    cin >> ps1;

    cout << "Nhap phan so thu hai:\n";
    cin >> ps2;

    cout << "\nPhan so 1: " << ps1 << endl;
    cout << "Phan so 2: " << ps2 << endl;

    cout << "\nTong hai phan so: " << ps1 + ps2 << endl;
    cout << "Hieu hai phan so: " << ps1 - ps2 << endl;
    cout << "Tich hai phan so: " << ps1 * ps2 << endl;
    cout << "Thuong hai phan so: " << ps1 / ps2 << endl;

    if (ps1 == ps2) {
        cout << "Hai phan so bang nhau.\n";
    } else if (ps1 > ps2) {
        cout << "Phan so 1 lon hon phan so 2.\n";
    } else {
        cout << "Phan so 1 nho hon phan so 2.\n";
    }

    double real;
    cout << "\nNhap so: ";
    cin >> real;

    cout << "\nCong voi so: " << ps1 + real << endl;
    cout << "Tru voi so: " << ps1 - real << endl;
    cout << "Nhan voi so: " << ps1 * real << endl;
    cout << "Chia voi so: " << ps1 / real << endl;

    return 0;
}
