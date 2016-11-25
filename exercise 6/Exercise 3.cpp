#include<iostream>
using namespace std;

class Animal
{
public:
    virtual void Speak()=0;
};

class Cat :public Animal
{
    void Speak()
    {
        cout<<"My name is Cat"<<endl;
    }
};

class Leopard:public Animal
{
    void Speak()
    {
        cout<<"My name is Leopard"<<endl;
    }
};

int main()
{
    Animal *pa;
    Cat cat;
    pa=&cat;
    pa->Speak();
    Leopard leopard;
    pa=&leopard;
    pa->Speak();
    return 0;
}
