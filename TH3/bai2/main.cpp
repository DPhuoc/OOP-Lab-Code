#include "SoPhuc.h"

int main() {
    SoPhuc sp1, sp2;
    double real;
    
    cout << "Nhap so phuc thu nhat:\n";
    cin >> sp1;
    
    cout << "Nhap so phuc thu hai:\n";
    cin >> sp2;
    
    cout << "\nSo phuc 1: " << sp1 << endl;
    cout << "So phuc 2: " << sp2 << endl;

    cout << "\nTong hai so phuc: " << sp1 + sp2 << endl;
    cout << "Hieu hai so phuc: " << sp1 - sp2 << endl;
    cout << "Tich hai so phuc: " << sp1 * sp2 << endl;
    cout << "Thuong hai so phuc: " << sp1 / sp2 << endl;
    
    if (sp1 == sp2) {
        cout << "Hai so phuc bang nhau.\n";
    } else {
        cout << "Hai so phuc khong bang nhau.\n";
    }

    cout << "\nNhap so thuc: ";
    cin >> real;

    cout << "\nCong so phuc voi so thuc: " << sp1 + real << endl;
    cout << "Tru so phuc voi so thuc: " << sp1 - real << endl;
    cout << "Nhan so phuc voi so thuc: " << sp1 * real << endl;
    cout << "Chia so phuc voi so thuc: " << sp1 / real << endl;

    return 0;
}
