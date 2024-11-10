#include <iostream>
#include "NgayThangNam.h"
using namespace std;

int main() {
    NgayThangNam date1, date2;
    cout << "Nhập ngày tháng năm đầu (dd mm yyyy): "; cin >> date1;
    cout << "Nhập ngày tháng năm sau (dd mm yyyy): "; cin >> date2;

    cout << endl;
    cout << "Date 1: " << date1 << endl;
    cout << "Date 2: " << date2 << endl;

    cout << endl;
    cout << "Date 1 tiến tới 10 ngày: " << date1 + 10 << endl;
    cout << "Date 2 lùi lại 7 ngày: " << date2 - 7 << endl;

    int daysBetween = date1 - date2;
    cout << "Khoảng cách giữa Date 1 và Date 2: " << daysBetween << " ngày" << endl;

    cout << endl;
    ++date1;
    cout << "Date 1 sau khi ++: " << date1 << endl;
    date1--;
    cout << "Date 1 sau khi --: " << date1 << endl;

    if (date1 == date2) {
        cout << "Date 1 là Date 2" << endl;
    } else if (date1 > date2) {
        cout << "Date 1 sau Date 2" << endl;
    } else {
        cout << "Date 1 trước Date 2" << endl;
    }

    return 0;
}
