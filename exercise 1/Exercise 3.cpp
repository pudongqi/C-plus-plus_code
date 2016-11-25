#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>
using namespace std;

class Ctriangle
{
    private:
        double C,S;
    public:
        void calculate_C(double x,double y,double z)
        {
            C=x+y+z;
        }
        void calculate_S(double x,double y,double z)
        {
            double p=(x+y+z)/2;
            S=sqrt(p*(p-x)*(p-y)*(p-z));
        }
        void printf_C()
        {
            cout<<"周长是"<<C<<endl;
        }
        void printf_S()
        {
            cout<<"面积是"<<S<<endl;
        }
};

int main()
{
    Ctriangle new_triangle;
    double a,b,c;
    cin>>a>>b>>c;
    new_triangle.calculate_C(a,b,c);
    new_triangle.calculate_S(a,b,c);
    new_triangle.printf_C();
    new_triangle.printf_S();
    return 0;
}
