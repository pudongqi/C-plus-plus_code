#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

class Rational
{
public:
    int numerator;
    int denominator;
    Rational()
    {
        numerator = 0;
        denominator = 1;
    }
    Rational(int numerator, int denominator)
    {
        this -> numerator = numerator;
        this -> denominator = denominator;
    }
    int getNumerator() const;
    int getDenominator() const;
    friend Rational operator + (Rational A, Rational B);
    friend Rational operator - (Rational A, Rational B);
    friend Rational operator * (Rational A, Rational B);
    friend Rational operator / (Rational A, Rational B);
    int operator [] (bool x);
    Rational operator ++ ();
    Rational operator ++ (int);
    Rational operator -- ();
    Rational operator -- (int);
    friend istream &operator >>(istream &is, Rational& A);
    friend ostream &operator << (ostream &os, Rational& A);

};

int gcd (int a, int b)
{
    if (b == 0) return a;
    return gcd (b, a % b);
}

int Rational::getNumerator() const
{
  return numerator;
}

int Rational::getDenominator() const
{
  return denominator;
}

Rational operator + (Rational A, Rational B)
{
    int Gcd = gcd(A.denominator, B.denominator);
    int Numerator = (A.numerator * B.denominator + A.denominator * B.numerator) / Gcd;
    int Denominator = A.denominator * B.denominator / Gcd;
    return Rational(Numerator, Denominator);
}

Rational operator - (Rational A, Rational B)
{
    int Gcd = gcd(A.denominator, B.denominator);
    int Numerator = (A.numerator * B.denominator - A.denominator * B.numerator) / Gcd;
    int Denominator = A.denominator * B.denominator / Gcd;
    return Rational(Numerator, Denominator);
}

Rational operator * (Rational A, Rational B)
{
    int Numerator = A.numerator * B.numerator;
    int Denominator = A.denominator * B.denominator;
    int Gcd = gcd(Denominator, Numerator);
    Numerator /= Gcd;
    Denominator /= Gcd;
    return Rational(Numerator, Denominator);
}

Rational operator / (Rational A, Rational B)
{
    int Numerator = A.numerator * B.denominator;
    int Denominator = A.denominator * B.numerator;
    int Gcd = gcd(Denominator, Numerator);
    Numerator /= Gcd;
    Denominator /= Gcd;
    return Rational(Numerator, Denominator);
}

int Rational::operator [] (bool x)
{
    if(x == 0) return this -> numerator;
    return this -> denominator;
}

Rational Rational::operator ++ ()
{
    int Gcd = gcd(this -> denominator, this -> numerator + this -> denominator);
    this -> numerator = (this -> numerator + this -> denominator) / Gcd;
    this -> denominator = this -> denominator / Gcd;
    return Rational(this -> numerator, this -> denominator);
}

Rational Rational::operator ++ (int)
{
    int Numerator = this -> numerator;
    int Denominator = this -> denominator;
    int Gcd = gcd(this -> denominator, this -> numerator + this -> denominator);
    this -> numerator = (this -> numerator + this -> denominator) / Gcd;
    this -> denominator = this -> denominator / Gcd;
    return Rational(Numerator, Denominator);
}

Rational Rational::operator -- ()
{
    int Gcd = gcd(this -> denominator, this -> numerator - this -> denominator);
    this -> numerator = (this -> numerator - this -> denominator) / Gcd;
    this -> denominator = this -> denominator / Gcd;
    return Rational(this -> numerator, this -> denominator);
}

Rational Rational::operator -- (int)
{
    int Numerator = this -> numerator;
    int Denominator = this -> denominator;
    int Gcd = gcd(this -> denominator, this -> numerator - this -> denominator);
    this -> numerator = (this -> numerator - this -> denominator) / Gcd;
    this -> denominator = this -> denominator / Gcd;
    return Rational(Numerator, Denominator);
}

istream &operator >>(istream &is, Rational& A)
{
    is >> A.numerator >> A.denominator;
    return is;
}
ostream &operator << (ostream &os, Rational& A)
{
    if(A.numerator < 0 || A.denominator < 0)
    os << "-" << abs(A.numerator) << "/" << abs(A.denominator) <<endl;
    else os << A.numerator << "/" << A.denominator <<endl;
    return os;
}


int main()
{
    Rational A, B, C;
    cin >> A >> B;
    cout << "A = " << A;
    cout << "B = " << B;
    C = A + B;
    cout << "C = A + B = " << C;
    C = A - B;
    cout << "C = A - B = " << C;
    C = A * B;
    cout << "C = A * B = " << C;
    C = A / B;
    cout << "C = A / B = " << C;
    C = A++;
    cout << "C = A++ = " << C;
    C = ++A;
    cout << "C = ++A = " << C;
    C = B--;
    cout << "C = B-- = " << C;
    C = --B;
    cout << "C = --B = " << C;

    return 0;
}
