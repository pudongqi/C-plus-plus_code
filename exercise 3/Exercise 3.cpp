#include<iostream>
using namespace std;

class StackOfIntegers
{
    private:
        int elements[100];
        int size;
    public:
        StackOfIntegers();
        bool Empty() const;
        int peek() const;
        void push(int value);
        int pop();
        int getSize() const;
};

StackOfIntegers::StackOfIntegers()
{
    size = 0;
}

bool StackOfIntegers::Empty() const
{
    if(size == 0)
        return true;
    return false;
}

int StackOfIntegers::peek() const
{
    return elements[size - 1];
}

void StackOfIntegers::push(int new_e)
{
    elements[size++] = new_e;
}

int StackOfIntegers::pop()
{
    int e = elements[size - 1];
    size--;
    return e;
}

int StackOfIntegers::getSize() const
{
    return size;
}

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
};


int main()
{
    StackOfIntegers stack;
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        if(MyInteger::isPrime(i))
        {
            int x = n;
            while(x % i == 0)
            {
                stack.push(i);
                x /= i;
            }
        }
    }
    while (!stack.Empty())
    {
        cout << stack.pop() << " ";
    }
    cout << endl;
    return 0;
}
