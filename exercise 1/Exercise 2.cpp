#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int a[100][100],b[100][100];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=n-1;j>=0;j--)
        {
            b[i][j]=a[n-j-1][i];
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<b[i][0];
        for(int j=1;j<n;j++)
        {
            cout<<" "<<b[i][j];
        }
        cout<<endl;
    }
    return 0;
}
