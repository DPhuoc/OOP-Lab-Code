#include "complex.h"
#include <cmath>
using namespace std;

Complex::Complex(double r, double i) : real(r), imag(i) {}

Complex Complex::operator + (const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);
}

Complex Complex::operator - (const Complex& other) const {
    return Complex(real - other.real, imag - other.imag);
}

Complex Complex::operator * (const Complex& other) const {
    double r = real * other.real - imag * other.imag;
    double i = real * other.imag + imag * other.real;
    return Complex(r, i);
}

Complex Complex::operator / (const Complex& other) const {
    double denom = other.real * other.real + other.imag * other.imag;
    double r = (real * other.real + imag * other.imag) / denom;
    double i = (imag * other.real - real * other.imag) / denom;
    return Complex(r, i);
}

bool Complex::operator == (const Complex& other) const {
    return (real == other.real && imag == other.imag);
}

std::istream& operator >> (std::istream& in, Complex& c) {
    cout << "Nhập phần thực: ";
    in >> c.real;
    cout << "Nhập phần ảo: ";
    in >> c.imag;
    return in;
}

std::ostream& operator << (std::ostream& out, const Complex& c) {
    if (c.imag >= 0) {
        out << c.real << " + " << c.imag << "i";
    } else {
        out << c.real << " - " << fabs(c.imag) << "i";
    }
    return out;
}