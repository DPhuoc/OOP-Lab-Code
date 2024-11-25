#include <iostream>
#include "Bo.h"
#include "Cuu.h"
#include "De.h"
using namespace std;

int main() {
    long long soBo, soCuu, soDe;
    cout << "Nhap so luong bo: "; cin >> soBo;
    cout << "Nhap so luong cuu: "; cin >> soCuu;
    cout << "Nhap so luong de: "; cin >> soDe;

    Bo bo(soBo);
    Cuu cuu(soCuu);
    De de(soDe);

    

}