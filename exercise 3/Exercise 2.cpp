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

int main()
{
    StackOfIntegers stack;
    const int n = 10;
    cout << "Please input " << n << " numbers. " << endl;
    for (int i = 0; i < 10; i++)
    {
        int x;
        cin >> x;
        stack.push(x);
    }
    while (!stack.Empty())
    {
        cout << stack.pop() << " ";
    }
    cout << endl;
    return 0;
}
