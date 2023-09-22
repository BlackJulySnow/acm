#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a=0,b=1,c=0,n=0;
    scanf("%d",&n);
    for(a=1,n<=20;a<=n;a++)
    {
        b=b*a;
        c=c+b;
    }
    printf("%d",c);
    return 0;
}