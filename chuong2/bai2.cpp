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

    bool operator > (const fraction& other) const {
        return (numerator * other.denominator) > (other.numerator * denominator);
    }
};

fraction a[1000000];
long long n;

int main() {
    cout << "Nhap so luong phan so mong muon: ";
    cin >> n;

    fraction sum;
    fraction maxA = -1000000;

    for (int i = 1; i <= n; i++) {
        cout << "Nhap phan so thu " << i << endl;
        a[i].input();
        sum = sum + a[i];
        if (a[i] > maxA) maxA = a[i];
    }    

    cout << "Tong cac phan so la "; sum.output();
    cout << "Phan so lon nhat la: "; maxA.output();
}