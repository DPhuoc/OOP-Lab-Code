#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex {
private:
    double real; 
    double imag; 

public:
    Complex(double r = 0.0, double i = 0.0);

    Complex operator + (const Complex& other) const;

    Complex operator - (const Complex& other) const;

    Complex operator * (const Complex& other) const;

    Complex operator / (const Complex& other) const;

    bool operator == (const Complex& other) const;

    friend std::istream& operator >> (std::istream& in, Complex& c);

    friend std::ostream& operator << (std::ostream& out, const Complex& c);
};

#endif