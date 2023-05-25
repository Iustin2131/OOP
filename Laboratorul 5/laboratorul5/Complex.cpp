#include "Complex.h"

Complex::Complex() : Complex(0, 0) {
}

Complex::Complex(double real, double imag) {
    real_data = real;
    imag_data = imag;
}

bool Complex::is_real() const {
    return imag() == 0;
}

double Complex::real() const {
    return real_data;
}

double Complex::imag() const {
    return imag_data;
}

double Complex::abs() const {
    return sqrt(real() * real() + imag() * imag());
}

Complex Complex::conjugate() const {
    return { real(), -imag() };
}

Complex& Complex::operator()(double real, double imag)
{
    real_data = real;
    imag_data = imag;
    return *this;
}

Complex& Complex::operator++()
{
    real_data = (real_data + 1);
    return *this;
}

Complex Complex::operator++(int)
{
    Complex nou=*this;
    operator++();
   
    return nou;
}

Complex& Complex::operator--()
{
    real_data = (real_data - 1);
    return *this;
}

Complex Complex::operator--(int)
{
    Complex nou=*this;
    operator--();

    return nou;
}



Complex operator+(const Complex& l, const Complex& r)
{
    double a = l.real() + r.real();
    double b = l.imag() + r.imag();

    return Complex(a, b);
}

Complex operator+(const Complex& l, double r)
{
    Complex n(r, 0);
    double a = l.real() + n.real();
    double b = l.imag() + n.imag();

    return Complex(a, b);
}

Complex operator+(double l, const Complex& r)
{
    Complex n(l, 0);
    double a = r.real() + n.real();
    double b = r.imag() + n.imag();

    return Complex(a, b);
}

Complex operator-(const Complex& l, const Complex& r)
{
    double a = l.real() - r.real();
    double b = l.imag() - r.imag();

    return Complex(a, b);
}

Complex operator-(const Complex& l, double r)
{
    Complex n(r, 0);
    double a = l.real() - n.real();
    double b = l.imag() - n.imag();

    return Complex(a, b);
}

Complex operator-(double l, const Complex& r)
{
    Complex n(l, 0);
    double a = r.real() - n.real();
    double b = r.imag() - n.imag();

    return Complex(a, b);
}
//(a+bi)(c+di)=(ac - bd) + i(ad + bc)
Complex operator*(const Complex& l, const Complex& r)
{
    double a = l.real() * r.real() - l.imag() * r.imag();
    double b = l.real() * r.imag() + l.imag() * r.real();

    return Complex(a, b);
}

Complex operator*(const Complex& l, double r)
{
    Complex n(r, 0);

    return l * n;
}

Complex operator*(double l, const Complex& r)
{
    Complex n(l, 0);

    return n * r;
}

Complex operator-(const Complex& obj)
{
    double a = obj.real()*(-1);
    double b = obj.imag()*(-1);

    return Complex(a, b);
}

bool operator==(const Complex& l, const Complex& r)
{
    if (l.real() == r.real() && l.imag()== r.imag())
        return true;

    return false;
}

bool operator!=(const Complex& m, const Complex& n)
{
    if (m == n)
        return false;
   
        return true;
}

std::ostream& operator<<(std::ostream& out, const Complex& complex)
{
    // daca ambele sunt zero, se va printa doar partea reala
// exemplu:                  5 + 4i
// sau:                     -3 - 2i
// daca e real:             -6
// daca nu are parte reala: 5i

    if (complex.real() == 0 && complex.imag() != 0) 
        out << complex.imag() << "i";
    else
    if (complex.real() != 0 && complex.imag() == 0) 
        out << complex.real();
    else
     if (complex.real() == 0 && complex.imag() == 0)
        out << complex.real();
     else
     if(complex.imag() > 0)
        out << complex.real()<<" + "<< complex.imag()<<"i";
    else
        out << complex.real() << " " << complex.imag() << "i";
        return out;
}
