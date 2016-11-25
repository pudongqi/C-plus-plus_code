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
    void display()
    {
        cout << numerator << "/" << denominator <<endl;
    }
    int getNumerator() const;
    int getDenominator() const;
    friend Rational operator + (Rational A, Rational B);
    friend Rational operator - (Rational A, Rational B);
    friend Rational operator * (Rational A, Rational B);
    friend Rational operator / (Rational A, Rational B);
    int compare(Rational B);
    bool equals(Rational B);
    int intvalue() const;
    double doublevalue() const;
    string toString() const;
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

int Rational::compare(Rational B)
{
    int a= this -> numerator * B.denominator;
    int b = this -> denominator * B.numerator;
    if(a > b) return 1;
    else if(a == b) return 0;
    else return -1;
}

bool Rational::equals(Rational B)
{
    if(this -> numerator * B.denominator == this -> denominator * B.numerator)
        return true;
    return false;
}

int Rational::intvalue() const
{
    return numerator/denominator;
}

double Rational::doublevalue() const
{
    return 1.0*numerator/denominator;
}

int main()
{
    Rational A(2, 5), B(3, 4), C;
    cout << "A = ", A.display();
    cout << "B = ", B.display();
    C = A + B;
    cout << "C = A + B = ", C.display();
    C = A - B;
    cout << "C = A - B = ", C.display();
    C = A * B;
    cout << "C = A * B = ", C.display();
    C = A / B;
    cout << "C = A / B = ", C.display();
    int temp = A.compare(B);
    if(temp == 1) cout << "A > B" <<endl;
    else if(temp == 0) cout << "A = B" <<endl;\
    else cout << "A < B" <<endl;
    cout << "A = " << A.intvalue() << endl;
    cout << "B = " << B.doublevalue() << endl;
    return 0;
}
