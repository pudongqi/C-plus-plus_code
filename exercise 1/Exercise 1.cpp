#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    char s1[10],s2[10];
    cin>>s1>>s2;
    if(s1[0]=='r')
    {
        if(s2[0]=='r') cout<<"ƽ��"<<endl;
        else if(s2[0]=='s') cout<<"��Ӯ"<<endl;
        else cout<<"��Ӯ"<<endl;
    }
    else if(s1[0]=='s')
    {
        if(s2[0]=='s') cout<<"ƽ��"<<endl;
        else if(s2[0]=='c') cout<<"��Ӯ"<<endl;
        else cout<<"��Ӯ"<<endl;
    }
    else
    {
        if(s2[0]=='c') cout<<"ƽ��"<<endl;
        else if(s2[0]=='r') cout<<"��Ӯ"<<endl;
        else cout<<"��Ӯ"<<endl;
    }
    return 0;
}
