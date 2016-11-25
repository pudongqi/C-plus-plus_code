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
        if(s2[0]=='r') cout<<"Æ½¾Ö"<<endl;
        else if(s2[0]=='s') cout<<"¼×Ó®"<<endl;
        else cout<<"ÒÒÓ®"<<endl;
    }
    else if(s1[0]=='s')
    {
        if(s2[0]=='s') cout<<"Æ½¾Ö"<<endl;
        else if(s2[0]=='c') cout<<"¼×Ó®"<<endl;
        else cout<<"ÒÒÓ®"<<endl;
    }
    else
    {
        if(s2[0]=='c') cout<<"Æ½¾Ö"<<endl;
        else if(s2[0]=='r') cout<<"¼×Ó®"<<endl;
        else cout<<"ÒÒÓ®"<<endl;
    }
    return 0;
}
