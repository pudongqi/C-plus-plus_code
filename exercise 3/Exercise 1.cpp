#include <iostream>
using namespace std;

class MyInteger
{
    private:
        int value;
    public:
        int getValue() const
        {
            return value;
        }
        MyInteger(int value)
        {
            this->value = value;
        }
        bool isPrime() const
        {
            return isPrime(value);
        }
        static bool isPrime(const MyInteger& o)
        {
            return isPrime(o.getValue());
        }
        static bool isPrime(int num)
        {
            if (num < 2)
            {
                return false;
            }
            for (int i = 2; i*i <= num; i++)
            {
                if (num % i == 0)
                    return false;
            }
            return true;
        }
        bool isEven() const
        {
            return isEven(value);
        }
        static bool isEven(int n)
        {
            if(n %2 == 0)
                return true;
            return false;
        }
        static bool isEven(const MyInteger& n)
        {
            return isEven(n.getValue());
        }
        bool equals(int anotherNum) const
        {
            if(value == anotherNum)
                return true;
            return false;
        }
        bool equals(const MyInteger& o) const
        {
            if(value == o.getValue())
                return true;
            return false;
        }
};

int main()
{
    int n;
    cout << "n1 = ";
    cin >> n;
    MyInteger n1(n);
    if(n1.isEven())
        cout << "n1 is even. " << endl;
    else cout << "n1 is not even. " << endl;
    if(n1.isPrime())
        cout << "n1 is prime. " << endl;
    else cout << "n1 is not prime. " << endl;
    if(n1.equals(1))
        cout << "n1 is equal 1."  << endl;
    else cout << "n1 is not equal 1."  << endl;
}
