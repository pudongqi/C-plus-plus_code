#include<iostream>
#include<string.h>
using namespace std;
class Vehicle
{
public:
    virtual void showinfo()=0;
protected:
    char Name[20];
};

class Car:public Vehicle
{
public:
    Car(char *name)
    {
        strcpy(Name,name);
    }
    void showinfo()
    {
        cout<<Name<<endl;
    }
protected:
    int Radius;
};

class Truck:public Vehicle
{
public:
    Truck(char *name)
    {
        strcpy(Name,name);
    }
    void showinfo()
    {
        cout<<Name<<endl;
    }
};

class Boat:public Vehicle
{
public:
    Boat(char *name)
    {
        strcpy(Name,name);
    }
    void showinfo()
    {
        cout<<Name<<endl;
    }
};

int main()
{
    Vehicle *vp;
    Car car("car");
    Truck truck("truck");
    Boat boat("boat");
    vp=&car;
    vp->showinfo ();
    vp=&truck;
    vp->showinfo ();
    vp=&boat;
    vp->showinfo ();
    return 0;
}
