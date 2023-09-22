#include "bits/stdc++.h"
#define ll long long
#define fore(i, l, r) for(int i = l;i <= r;i++)
using namespace std;

int main() {
    int n,k;
    cin>>n>>k;
    ll ans = k;
    fore(i,1,n-1){
        ans *= k - 1;
    }
    cout<<ans;
    return 0;
}