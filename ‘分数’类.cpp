//分数类
#include<iostream>
#include<stdlib.h>
using namespace std;

class Fraction
{
public:
	Fraction(int n=0, int d=1,):nume(n),deno(d){simplify();}
	Fraction(double d);//double类型转换Fraction构造函数
	Fraction(const string& str);//string类型转换Fraction构造函数
	Fraction(const Fraction& f): nume.(f.nume),deno(f.deno){}//复制构造函数
	void display();//显示分数
private:
	void simplify();//简化分数
	int nume,deno;//分子nume, 分母deno

};

Fraction::Fraction(const string& str):nume(0),deno(1)
{
	char buf[200];
	int i=str.find('/');
	j=str.length()-i-1;
	if(i>=0)
	{
		str.copy(buf,i,0);
		buf[i]=0;
		nume = atoi(buf);//前面的字串转换为分子

		str.copy(buf,j,i+1);
		buf[j]=0;
		deno = atoi(buf);//后面的字串转换为分母
	}
	simplify();
}

Fraction::Fraction(double d):nume(d),deno(1)//分子初始为d的整数部分
{
	d=d-nume;
	while( int(d*10)!=0 )
	{
		nume = nume*10+int(d*10);
		deno = deno*10;
		d=d*10-int(d*10);
	}
	simplify();
}

void Fraction::display()
{
	if( deno!=0 && deno!=1 && nume!=deno)
		cout<<nume<<"/"<<deno<<endl;
	else
		cout<<nume<<endl;
}

void Fraction::simplify()
{
	int m,n,r,s=1
	if( nume!=0 && deno!=0)
	{
		if(deno<0) s=-s, deno = -deno;
		if(nume<0) s=-s, nume = -nume;
		m = nume;
		n = deno;
		while(n!=0)
			r = m%n, m=n, n=r;
		if(m!=0)
			nume=s*nume/m, deno=deno/m;
	}
	else
		nume =0, deno=1;
}