#include <iostream>
using namespace std;

class Complex {
private:
    float real; 
    float ima; 

public:
    Complex(float r = 0, float i = 0) : real(r), ima(i) {}

    void input() {
        cout << "Nhập phần thực: "; cin >> real;
        cout << "Nhập phần ảo: "; cin >> ima;
    }

    void output() const {
        cout << real << (ima >= 0 ? " + " : " - ") << abs(ima) << "i" << endl;
    }

    Complex operator + (Complex other) const {
        return Complex(real + other.real, ima + other.ima);
    }

    Complex operator - (Complex other) const {
        return Complex(real - other.real, ima - other.ima);
    }

    Complex operator*(Complex other) const {
        return Complex(real * other.real - ima * other.ima, real * other.ima + ima * other.real);
    }

    Complex operator / (Complex other) const {
        float denominator = other.real * other.real + other.ima * other.ima;
        if (denominator == 0) {
            throw invalid_argument("Không thể chia cho số phức bằng 0.");
        }
        return Complex((real * other.real + ima * other.ima) / denominator, (ima * other.real - real * other.ima) / denominator);
    }
};

int main() {
    Complex num1, num2;

    cout << "Nhập số phức thứ nhất:" << endl; num1.input();

    cout << "Nhập số phức thứ hai:" << endl; num2.input();

    cout << "Số phức thứ nhất: "; num1.output();
    cout << "Số phức thứ hai: "; num2.output();
    cout << "Tổng của hai số phức: "; (num1 + num2).output();
    cout << "Hiệu của hai số phức: "; (num1 - num2).output();
    cout << "Tích của hai số phức: "; (num1 * num2).output();
    cout << "Thương của hai số phức: "; (num1 / num2).output();
}