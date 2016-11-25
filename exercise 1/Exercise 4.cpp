#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>
using namespace std;

class Point
{
    private:
        double x,y;
    public:
        void scanf_point()
        {
            cin>>x>>y;
        }
        double distance (const Point& p)
        {
            cout<<sqrt((this->x-p.x)*(this->x-p.x)+(this->y-p.y)*(this->y-p.y))<<endl;
        }
};

int main()
{
    Point a;
    Point b;
    a.scanf_point();
    b.scanf_point();
    a.distance(b);
    return 0;
}
