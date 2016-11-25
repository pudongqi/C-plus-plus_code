#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int a[100];
int n,w,s;
void solve()
{
    int N=n;
    w--;
    while(N!=1)
    {
        int x=(w+s-1)%N;
        int flag=0;
        for(int i=0;i<n;i++)
        {
            if(flag==x&&a[i]!=0)
            {
                printf("%d ",a[i]);
                a[i]=0;
                N--;
                w=x;
                break;
            }
            if(a[i]!=0) flag++;
        }
    }
}
int main()
{
    scanf("%d%d%d",&n,&w,&s);
    for(int i=0;i<n;i++)
    {
        a[i]=i+1;
    }
    solve();
    for(int i=0;i<n;i++)
    {
        if(a[i]!=0)
        {
            printf("%d\n",a[i]);
            break;
        }
    }
    return 0;
}
