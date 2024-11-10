#include <bits/stdc++.h>
using namespace std;

class fraction {
private:
    int numerator, denominator;

    int lcm(int a, int b) {
        if (b == 0) return a;
        return lcm(b, a % b);
    }

    void reduce() {
        int tmp = lcm(numerator, denominator);
        numerator /= tmp;
        denominator /= tmp;
    }

public:
    fraction(int tu = 0, int mau = 1) : numerator(tu), denominator(mau) {
        reduce();
    }

    void input() {
        cout << "Nhập tử số: ";
        cin >> numerator;
        do {
            cout << "Nhập mẫu số: ";
            cin >> denominator;
            if (denominator == 0) {
                cout << "Mẫu số phải khác 0. Vui lòng nhập lại.\n";
            }
        } while (denominator == 0);
        reduce();
    }

    string output() const {
        if (denominator == 1) {
            return to_string(numerator);
        } else {
            return to_string(numerator) + "/" + to_string(denominator);
        }
    }

    int getNumer() {
        return numerator;
    }

    bool operator < (const fraction& other) const {
        return static_cast<double>(numerator) / denominator < static_cast<double>(other.numerator) / other.denominator;
    }
};


class arrPhanSo {
private:
    fraction* arr;
    int size; 

public:
    bool isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    void inArr() {
        cout << "Nhập số lượng phần tử của mảng: "; cin >> size; 
        arr = new fraction[size];
        for (int i = 0; i < size; i++) {
            cout << "Nhập phân số thứ " << i << endl;
            arr[i].input();
        }
    }

    void outArr() {
        for (int i = 0; i < size; i++) {
            cout << "Phân số thứ " << i << ": " << arr[i].output() << endl;
        }
    }

    void genRan() {
        cout << "Nhập số lượng phần tử của mảng: "; cin >> size; 
        arr = new fraction[size];
        for (int i = 0; i < size; i++) {
            int tu = rand() - INT_MAX / 2; 
            int mau;
            do {
                mau = rand() - INT_MAX / 2; 
            } while (mau == 0);          
            arr[i] = fraction(tu, mau);
        }
    }

    fraction findMax() {
        fraction res = arr[0];
        for (int i = 1; i < size; i++) {
            if (res < arr[i]) res = arr[i];
        }
        return res;
    }

    int cntPrime() {
        int cnt = 0;
        for (int i = 0; i < size; i++) {
            if (isPrime(arr[i].getNumer())) cnt++;
        }
        return cnt;
    }

    void sortInc() {
        sort(arr, arr + size);
    }
};

string menu = 
"\n======== MENU ========\n"
"1. Nhập danh sách phân số\n"
"2. Xuất danh sách phân số\n"
"3. Tạo n phân số ngẫu nhiên\n"
"4. Tìm phân số có giá trị lớn nhất\n"
"5. Đếm số phân số có tử là số nguyên tố\n"
"6. Sắp xếp phân số theo thứ tự tăng dần\n"
"0. Thoát\n"
"======================\n"
"Nhập lựa chọn của bạn: ";

int main() {
    arrPhanSo a;
    int choice;
    do {
        cout << menu;
        cin >> choice;

        switch(choice) {
            int x, min_le;
            case 0:
                cout << "Thoát chương trình.\n";
                break;
            case 1:
                a.inArr();
                break;
            case 2:
                a.outArr();
                break;
            case 3:
                a.genRan();
                break;
            case 4:
                cout << "Phần từ lớn nhất của mảng là: " << a.findMax().output() << endl;
                break;
            case 5:
                cout << "Số phân số có tử là số nguyên tố là: " << a.cntPrime() << endl; 
                break;
            case 6:
                a.sortInc();
                break;
        }
    } while(choice != 0);
}