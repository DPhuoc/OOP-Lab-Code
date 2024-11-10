#include <iostream>
#include "ThoiGian.h"
using namespace std;

int main() {
    ThoiGian tg1(2, 30, 45); 
    ThoiGian tg2(1, 15, 20); 

    cout << "Time1: " << tg1 << endl;
    cout << "Time2: " << tg2 << endl;

    cout << endl << "Time1 + Time2: " << tg1 + tg2 << endl;

    ThoiGian tg4 = tg1 + 3600; 
    // cout << endl << "Time1";

    ThoiGian tg5 = tg1 - 500; 
    // tg5.Xuat();

    if (tg1 == tg2) {
        cout << "Hai thoi gian bang nhau." << endl;
    } else {
        cout << "Hai thoi gian khac nhau." << endl;
    }

    return 0;
}
