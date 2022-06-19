#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
#define ll long long
using namespace std;
int main(){
    ll n;
    scanf("%lld",&n);
    ll ans = 0,m=sqrt(n);
    for(ll i=1; i<=m; i++)
        ans += n/i;
    ans<<=1;
    ans-=m*m;
    printf("%lld\n",ans);
    return 0;
}
