#include <iostream>
using namespace std;

class fraction {
private:
    int numerator, denominator;

    int lcm(int a, int b) {
        if (b == 0) return a;
        return lcm(b, a % b);
    }

    void rutGon() {
        int tmp = lcm(numerator, denominator);
        numerator /= tmp;
        denominator /= tmp;
    }

public:
    fraction(int tu = 0, int mau = 1) : numerator(tu), denominator(mau) {
        rutGon();
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
        rutGon();
    }

    void output() const {
        if (denominator == 1) {
            cout << numerator << endl;
        } else {
            cout << numerator << "/" << denominator << endl;
        }
    }

    fraction operator + (const fraction& other) const {
        int tu = numerator * other.denominator + other.numerator * denominator;
        int mau = denominator * other.denominator;
        return fraction(tu, mau);
    }
    
    fraction operator - (const fraction& other) const {
        int tu = numerator * other.denominator - other.numerator * denominator;
        int mau = denominator * other.denominator;
        return fraction(tu, mau);
    }

    fraction operator * (const fraction& other) const {
        int tu = numerator * other.numerator;
        int mau = denominator * other.denominator;
        return fraction(tu, mau);
    }

    fraction operator / (const fraction& other) const {
        int tu = numerator * other.denominator;
        int mau = denominator * other.numerator;
        return fraction(tu, mau);
    }

    bool operator>(const fraction& other) const {
        return (numerator * other.denominator) > (other.numerator * denominator);
    }
};
    
int main() {
    fraction ps1, ps2;

    cout << "Nhập phân số thứ nhất:\n";
    ps1.input();
    cout << "Nhập phân số thứ hai:\n";
    ps2.input();

    fraction tong = ps1 + ps2;
    fraction hieu = ps1 - ps2;
    fraction tich = ps1 * ps2;
    fraction thuong = ps1 / ps2;

    cout << "Tổng: "; tong.output();
    cout << "Hiệu: "; hieu.output();
    cout << "Tích: "; tich.output();
    cout << "Thương: "; thuong.output();

    return 0;
}
