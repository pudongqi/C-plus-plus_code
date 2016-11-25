#include<iostream>
#include<string.h>
using namespace std;

class Shape
{
public:
    virtual void Area()=0;
};

class Rectangle:public Shape
{
public:
    Rectangle(double w,double h)
    {
        width=w,height=h;
    }
    void Area()
    {
        cout<<width*height<<endl;
    }

protected:
    double width,height;
};

class Circle:public Shape
{
public:
    Circle(double r)
    {
        radius=r;
    }
    void Area()
    {
        cout<<3.14*radius*radius<<endl;
    }

protected:
    double radius;
};

int main()
{
    Shape *sp;
    Rectangle re1(10,6);
    Circle cir1(4.0);
    sp=&re1;
    sp->Area ();
    sp=&cir1;
    sp->Area ();
    return 0;
}
