#include<iostream>
#include<stdio.h>
#include<math.h>
const double pi=acos(-1.0);
class Circle
{
    public:
        double S;
        void Calculate_S(double r)
        {
            S=r*r*pi;
        }
};

double sum (Circle circleArray[ ], int size)
{
    double sum=0;
    for(int i=0;i<size;i++)
    {
        sum += circleArray[i].S;
    }
    return sum;
}

int main()
{
    const int _size=10;
    Circle circleArray[_size];
    for(int i=0;i<_size;i++)
    {
        double r;
        scanf("%lf",&r);
        circleArray[i].Calculate_S(r);
    }
    printf("%.6lf\n",sum(circleArray, _size));
    return 0;
}
